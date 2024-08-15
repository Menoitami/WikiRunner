#include "personclass.h"

PersonClass::PersonClass() {}

PersonClass::~PersonClass(){}

PersonClass::PersonClass(QJsonDocument& doc){

    QJsonObject obj =  doc.object();

    name = obj.value("Nickname").toString();
    image = obj.value("Image").toString();
}

PersonClass::PersonClass(const PersonClass& other){

    name = other.name;
    image = other.image;


}

PersonClass::PersonClass(PersonClass&& other) noexcept{

    name = other.name;
    image = other.image;

    other.name = NULL;
    other.image = NULL;


}

PersonClass& PersonClass::operator=(const PersonClass& other){
    if (this == &other)  // Проверка на самоприсваивание
        return *this;


    this->name = other.name;
    this->image = other.image;

    return *this;
}


PersonClass& PersonClass::operator=(PersonClass&& other) noexcept{

    if (this == &other)  // Проверка на самоприсваивание
        return *this;

    name = other.name;
    image = other.image;

    other.name = NULL;
    other.image = NULL;

    return *this;

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





