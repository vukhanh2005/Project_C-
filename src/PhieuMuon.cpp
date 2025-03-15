#include "..\\include\\PhieuMuon.h"

void PhieuMuon::nhap()
{
    cout << "Nhap ma phieu muon: ";
    getline(cin, id);
    cout << "Nhap ngay muon: ";
    getline(cin, ngayMuon);
    cout << "Nhap ngay tra: ";
    getline(cin, ngayTra);
    cout << "Nhap trang thai (0: chua tra, 1: da tra): ";
    cin >> status;
}
void PhieuMuon::xuat()
{
    cout << "Ma phieu muon: " << id << endl;
    cout << "Ngay muon: " << ngayMuon << endl;
    cout << "Ngay tra: " << ngayTra << endl;
    cout << "Trang thai: " << (status ? "Da tra" : "Chua tra") << endl;
    cout << "Danh sach id sach da muon: " << endl;
    for (int i = 0; i < listIdSach.size(); i++)
    {
        cout << listIdSach[i] << " " << endl;
    }
}
string PhieuMuon::getID()
{
    return id;
}
string PhieuMuon::getNgayMuon()
{
    return ngayMuon;
}
string PhieuMuon::getNgayTra()
{
    return ngayTra;
}
bool PhieuMuon::getStatus()
{
    return status;
}
void PhieuMuon::setStatus(bool status)
{
    this->status = status;
}
