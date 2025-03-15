#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "..\\include\\Sach.h"
#include "..\\include\\ListBookInLibrary.h"
using namespace std;

class PhieuMuon
{
    string id;
    string ngayMuon;
    string ngayTra;
    bool status; //1.Chua tra 0.Da tra
    
    public:
        vector<string> listIdSach;
        void nhap();
        void xuat();
        string getID();
        string getNgayMuon();
        string getNgayTra();
        bool getStatus();
        void setStatus(bool status);
};