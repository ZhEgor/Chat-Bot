#include "help.h"
#include "ui_help.h"
#include <QTextBrowser>
Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    ui->verticalLayout->setAlignment(Qt::AlignCenter);
}

Help::~Help()
{
    delete ui;
}

void Help::SendSpecialization(QList<QPair<QString, QList<QString>>> *specialization, QJsonDocument &interface){
    this->specialization = specialization;
    ui->HowToUse->setText(interface.object().value("HowToUse").toString());
    setTable(interface);
}

void Help::setTable(QJsonDocument &interface){
    ui->table->verticalHeader()->hide();
    ui->table->horizontalHeader()->hide();
    ui->table->setRowCount(7);
    ui->table->setColumnCount(2);
    QTableWidgetItem *temp1 = new QTableWidgetItem(interface.object().value("Specialization").toString());
    QTableWidgetItem *temp2 = new QTableWidgetItem(interface.object().value("Service").toString());
    ui->table->setItem(0, 0, temp1);
    ui->table->setItem(0, 1, temp2);
    for(int i = 0; i < specialization->size(); i++){
        QTextBrowser *r1 = new QTextBrowser();
        r1->setText(specialization->at(i).first);
        QTextBrowser *r2 = new QTextBrowser();
        r2->clear();
        for(int j =0; j < specialization->at(i).second.size(); j++){
            r2->append(specialization->at(i).second.at(j));
        }
        ui->table->setCellWidget(i+1, 0 , r1);
        ui->table->setCellWidget(i+1, 1 , r2);
    }
    ui->table->setDragEnabled(false);
    ui->table->resizeColumnsToContents();
    ui->table->resizeRowsToContents();
}
