#include "..\\include\\ThuThu.h"

void ThuThu::nhap()
{
    cin.ignore();
    cout << "Nhap ma thu thu: ";
    getline(cin, id);
    cout << "Nhap ten thu thu: ";
    getline(cin, name);
    cout << "Nhap so dien thoai: ";
    getline(cin, phone);
    cout << "Nhap email: ";
    getline(cin, email);
}
void ThuThu::xuat()
{
    cout << "Ma thu thu: " << id << endl;
    cout << "Ten thu thu: " << name << endl;
    cout << "So dien thoai: " << phone << endl;
    cout << "Email: " << email << endl;
}