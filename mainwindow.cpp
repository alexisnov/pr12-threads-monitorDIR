#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Создаём поток
    dMonitor = new dirMonitor("monitor","E:\\Qt-projects\\oop\\build-pr12-threads-Desktop_Qt_5_14_1_MinGW_32_bit-Debug");
    //Связываем сигналы/слоты
    connect(dMonitor,SIGNAL(dirChanged()),this,SLOT(dirChanged()));
    //Запускаем поток
    dMonitor->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dirChanged(){
    QString text = "! Состояние папки изменилось";
    ui->label->setText(text);
    ui->pushButton->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    QString text = "Состояние папки не изменилось";
    ui->label->setText(text);
    ui->pushButton->setEnabled(false);
}
