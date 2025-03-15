#pragma once
#include <iostream>
#include <string>

using namespace std;
class Sach
{
    string id;
    string name;
    string author;
    string type;
    bool status;
    int price;
    
    public:
        Sach();
        Sach(string id, string name, string author, string type, int price, bool status);
        void nhap();
        void xuat();
        string getId();
        string getName();
        string getAuthor();
        string getType();
        int getPrice();
        bool getStatus();
        void setStatus(bool status);
        void setId(string id);
};