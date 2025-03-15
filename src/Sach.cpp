#include "../include/Sach.h"


void Sach::nhap()
{
    cout << "Nhap ma sach: ";
    getline(cin, id);
    cout << "Nhap ten sach: ";
    getline(cin, name);
    cout << "Nhap ten tac gia: ";
    getline(cin, author);
    cout << "Nhap the loai: ";
    getline(cin, type);
    cout << "Nhap gia: ";
    cin >> price;
    cout << "Nhap trang thai (0: cho muon, 1: da cho muon): ";
    cin >> status;
}
void Sach::xuat()
{
    cout << "Ma sach: " << id << endl;
    cout << "Ten sach: " << name << endl;
    cout << "Tac gia: " << author << endl;
    cout << "The loai: " << type << endl;
    cout << "Gia: " << price << endl;
    cout << "Trang thai: " << (status ? "Free" : "Busy") << endl;
}
string Sach::getId()
{
    return id;
}
void Sach::setId(string id)
{
    this->id = id;
}
Sach::Sach()
{
    id = "";
    name = "";
    author = "";
    type = "";
    status = 0;
    price = 0;
}
Sach::Sach(string id, string name, string author, string type, int price, bool status)
{
    this->id = id;
    this->name = name;
    this->author = author;
    this->type = type;
    this->price = price;
    this->status = status;
}
string Sach::getName()
{
    return name;
}
string Sach::getAuthor()
{
    return author;
}
string Sach::getType()
{
    return type;
}
int Sach::getPrice()
{
    return price;
}
bool Sach::getStatus()
{
    return status;
}
void Sach::setStatus(bool status)
{
    this->status = status;
}