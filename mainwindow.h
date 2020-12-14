#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFile>
#include <QList>
#include <QPair>
#include <QJsonArray>
#include "dentist.h"
#include "dentistry.h"
#include "hashtablebyname.h"
#include "hashtablebyspecialization.h"
#include "hashtablebynameofdentistry.h"
#include "help.h"
#include "detaileddentist.h"
#include "commentsdentist.h"
#include "developers.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QJsonDocument dateDentist;
    QJsonArray dateDentistArr;

    QJsonDocument dateDentistry;
    QJsonArray dateDentistryArr;

    QJsonDocument dateSpec;
    QJsonArray dateSpecArr;

    QJsonDocument interface;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SearchByName(QString SearchWord);
    void SearchBySpecialization(QString SearchWord);
    void SearchByDentistry(QString SearchWord);
    void ShowDentist(QList<Dentist*> *temp);
    QList<Dentist*> sort(QList<Dentist*> *list);
    void OpenSpec();
    void OpenDentist();
    void OpenDentistry();
    void OpenInterface();
    void SaveDentist();
public slots:
         void SendDetailed(Dentist* temp);
         void SendComments(Dentist* temp);
         void SendShowDentistFromDentistry(QString temp);
         void SendShowDentistFromSpecialization(QString temp);
private slots:
    void on_Send_clicked();
    void on_actHelp_triggered();

    void on_actionEng_triggered();

    void on_actionUkr_triggered();

    void on_actDevelops_triggered();

    void on_actionDentists_triggered();

    void on_actionDentistry_triggered();

    void on_actionSpecializations_triggered();

    void on_actionClose_triggered();

private:
    Ui::MainWindow *ui;
    QList<Dentist*> listDentist;
    QList<Dentistry*> listDentistry;
    QList<QPair<QString, QList<QString>>> specialization;
    HashTableByName hashTableByName;
    HashTableByNameOfDentistry hashTableByNameOfDentistry;
    HashTableBySpecialization hashTableBySpecialization;
    QString pathFileDentist;
    QString pathFileDentistry;
    QString pathFileSpec;
    QString pathInterface;
};
#endif // MAINWINDOW_H
