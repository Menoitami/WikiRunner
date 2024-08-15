#include "personclass.h"

PersonClass::PersonClass() {}

PersonClass::PersonClass(QJsonDocument& doc){

    QJsonObject obj =  doc.object();

    name = obj.value("Nickname").toString();
    image = obj.value("Image").toString();
    qDebug()<<name<<image;

}



void PersonClass::setName(QString& name){

    this->name= name;

}

void PersonClass::setImage(QString& file){

    image = file;
}

QString& PersonClass::getName(){

    return name;
}

QString& PersonClass::getImage(){

    return image;
}





