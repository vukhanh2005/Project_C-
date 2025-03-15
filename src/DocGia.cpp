#include "..\\include\\DocGia.h"


void DocGia::nhap()
{
    cin.ignore();
    cout << "Nhap ma doc gia: ";
    getline(cin, id);
    cout << "Nhap ten doc gia: ";
    getline(cin, name);
    cout << "Nhap so dien thoai: ";
    getline(cin, phone);
    cout << "Nhap email: ";
    getline(cin, email);
}
void DocGia::xuat()
{
    cout << "Ma doc gia: " << id << endl;
    cout << "Ten doc gia: " << name << endl;
    cout << "So dien thoai: " << phone << endl;
    cout << "Email: " << email << endl;
}