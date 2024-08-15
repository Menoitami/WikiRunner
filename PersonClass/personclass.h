#ifndef PERSONCLASS_H
#define PERSONCLASS_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

class PersonClass
{
public:

    PersonClass(QJsonDocument& doc);
    void setName(QString& name);
    void setImage(QString& file);
    QString& getName();
    QString& getImage();



private:

    PersonClass();
    QString name;
    QString image;
    //QString id;

};

#endif // PERSONCLASS_H
