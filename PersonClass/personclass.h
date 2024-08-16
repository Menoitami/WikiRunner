#ifndef PERSONCLASS_H
#define PERSONCLASS_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QFileInfo>

class PersonClass
{
public:

    PersonClass();
    PersonClass(QJsonDocument& doc);
    PersonClass(const PersonClass& other);
    PersonClass(PersonClass&& other) noexcept;
    PersonClass& operator=(const PersonClass& other);
    PersonClass& operator=(PersonClass&& other) noexcept;


    void setName(QString& name);
    void setImage(QString& file);
    QString& getName();
    QString& getImage();


    ~PersonClass();


private:

    QJsonDocument doc;
    QString name;
    QString image;
    //QString id;

};

#endif // PERSONCLASS_H
