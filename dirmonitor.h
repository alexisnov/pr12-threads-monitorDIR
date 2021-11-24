#ifndef DIRMONITOR_H
#define DIRMONITOR_H

#include <QThread>
#include <QDir>

/**
 * @brief Класс мониторинга состояния папки
 */
class dirMonitor : public QThread
{
    Q_OBJECT
public:
    explicit dirMonitor(QString threadName,QString path);
    // Переопределяем метод run(), в котором будет
    // располагаться выполняемый код
    void run();
signals:
    void dirChanged();

private:
    QString name;//Имя потока
    QString path;//Путь папки
    QDir dir;//Объект для сохранения папки
};

#endif // DIRMONITOR_H
