#ifndef HASHTABLEBYSPECIALIZATION_H
#define HASHTABLEBYSPECIALIZATION_H
#include "dentist.h"
#include <QString>
#include <QList>
#include <QPair>

class HashTableBySpecialization
{
public:
    struct Node
    {
        QString key;
        QList<Dentist*> listOfDentists;
    };

    HashTableBySpecialization();
    ~HashTableBySpecialization();
    void push(Dentist* currentOfDentist);
    void search(QString key, QList<Dentist*> *temp);
    void setKeyWords(QList<QPair<QString, QList<QString>>> *keyWordsForSearchBySpec);
    void clear();
private:
    Node* arr;
    QList<QPair<QString, QList<QString>>> *keyWordsForSearchBySpec;
    QString searchByKeyWords(QString keyWords);
    int hashing(QString key);
    int size;
};

#endif // HASHTABLEBYSPECIALIZATION_H
