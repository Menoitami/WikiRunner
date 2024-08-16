#include "personclass.h"

PersonClass::PersonClass() {}


PersonClass::PersonClass(QJsonDocument& doc){

    QJsonObject obj =  doc.object();

    this->doc = doc;

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


PersonClass::~PersonClass(){

    QFileInfo fileInfo("../../LocalSettings/Person.json");
    qDebug() << "Attempting to write to:" << fileInfo.absoluteFilePath();

    QFile file(fileInfo.absoluteFilePath());


    if (doc.isNull()) {
        qWarning("The JSON document is null. Make sure it is initialized properly.");
        return;
    }


    QJsonObject obj = doc.object();
    obj.insert("Nickname", name);
    obj.insert("Image", image);
    doc.setObject(obj);


    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open file for writing.");
        return;
    }


    QTextStream stream(&file);
    stream << doc.toJson(QJsonDocument::Indented);


    if (stream.status() != QTextStream::Ok) {
        qWarning("Failed to write JSON data to file.");
    }

    file.close();
}





