#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include <QPair>
#include <QList>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

namespace Ui {
class Help;
}

class Help : public QWidget
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();
    QList<QPair<QString, QList<QString>>> *specialization;
    void SendSpecialization(QList<QPair<QString, QList<QString>>> *specialization, QJsonDocument &interface);
    void setTable(QJsonDocument &interface);

private:
    Ui::Help *ui;
};

#endif // HELP_H
