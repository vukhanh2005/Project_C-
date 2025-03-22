#include <iostream>
#include "Sach.cpp"
#include "ThuThu.cpp"
#include "DocGia.cpp"
#include "ListBookInLibrary.cpp"
#include "PhieuMuon.cpp"
#include <SFML\Graphics.hpp>
#include <thread>
#include <chrono>
#include <string>
#include <atomic>
#include <mutex>
#include <fstream>
using namespace std;
int count = 0;
int soSachDaMuon = 0;
std::atomic<bool> isInMenu1;
std::atomic<bool> isLoginSegment(true);
std::atomic<bool> isPhieuMuonWindowTurnOn(false);
std::atomic<bool> isMainWindowTurnOn(false);
std::atomic<bool> isSearchWindowTurnOn(false);
std::mutex mtx;
ListBook danhsach;
ListBook searchList;
std::vector<PhieuMuon> listPhieuMuon;
std::vector<DocGia> listDocGia;
int choice;
ofstream oFile;
ifstream iFile;
string convertInt_String(int x)
{
    return (to_string(x));
}
//Luồng 0
void loginTerminal()
{
    while (isLoginSegment == true)
    {
        string username, password;
        cout << "User Name: "; getline(cin, username);
        cout << "Password: "; getline(cin, password);
        if(username == "admin" && password == "123")
        {
            cout << "Dang nhap thanh cong" << endl;
            isInMenu1 = false;
            isLoginSegment = false;
            isMainWindowTurnOn = true;
        }
        else if(username == "NVK" && password == "123")
        {
            cout << "Dang nhap thanh cong" << endl;
            isInMenu1 = true;
            isLoginSegment = false;
            isMainWindowTurnOn = true;
        }
        else
        {
            cout << "Sai ten dang nhap hoac mat khau-Vui long nhap lai" << endl;
        }
    }
}
//Luồng 1
void mainWindow()
{
    while (isLoginSegment == true)
    {
        continue;
    }
    if(isMainWindowTurnOn)
    {
        sf::RenderWindow window(sf::VideoMode({1000, 1000}), "LIBRARY", sf::Style::Close);

        //Font
        sf::Font font;
        if(!font.openFromFile("Arial.ttf"))
        {
            std::cout << "Can't load font" << std::endl;
            return;
        }
        std::vector<sf::RectangleShape> lines;
        //Line
        sf::RectangleShape line(sf::Vector2f(1000, 1));
        line.setPosition({0, 100});
        line.setFillColor(sf::Color::Blue);
        //Line1
        sf::RectangleShape line1(sf::Vector2f(1, 100));
        line1.setPosition({100, 0});
        line1.setFillColor(sf::Color::Blue);
        //Line2
        sf::RectangleShape line2(sf::Vector2f(1, 100));
        line2.setPosition({300, 0});
        line2.setFillColor(sf::Color::Blue);
        //Line3
        sf::RectangleShape line3(sf::Vector2f(1, 100));
        line3.setPosition({500, 0});
        line3.setFillColor(sf::Color::Blue);
        //Line4
        sf::RectangleShape line4(sf::Vector2f(1, 100));
        line4.setPosition({700, 0});
        line4.setFillColor(sf::Color::Blue);
        //Line5
        sf::RectangleShape line5(sf::Vector2f(1, 100));
        line5.setPosition({900, 0});
        line5.setFillColor(sf::Color::Blue);
        //Push
        lines.push_back(line1);
        lines.push_back(line2);
        lines.push_back(line3);
        lines.push_back(line4);
        lines.push_back(line5);
        //Vector text
        std::vector<sf::Text> texts;
        //Text1
        sf::Text text1(font, "ID", 20);
        float x1 = text1.getGlobalBounds().size.x;
        float y1 = text1.getGlobalBounds().size.y;
        text1.setPosition({50 - x1/2, 50 - y1/2});
        text1.setFillColor(sf::Color::Green);
        //Text2
        sf::Text text2(font, "NAME", 20);
        float x2 = text2.getGlobalBounds().size.x;
        float y2 = text2.getGlobalBounds().size.y;
        text2.setPosition({200 - x2/2, 50 - y2/2});
        text2.setFillColor(sf::Color::Green);
        //Text3
        sf::Text text3(font, "AUTHOR", 20);
        float x3 = text3.getGlobalBounds().size.x;
        float y3 = text3.getGlobalBounds().size.y;
        text3.setPosition({400 - x3/2, 50 - y3/2});
        text3.setFillColor(sf::Color::Green);
        //Text4
        sf::Text text4(font, "TYPE", 20);
        float x4 = text4.getGlobalBounds().size.x;
        float y4 = text4.getGlobalBounds().size.y;
        text4.setPosition({600 - x1/2, 50 - y1/2});
        text4.setFillColor(sf::Color::Green);
        //Text5
        sf::Text text5(font, "PRICE", 20);
        float x5 = text5.getGlobalBounds().size.x;
        float y5 = text5.getGlobalBounds().size.y;
        text5.setPosition({800 - x5/2, 50 - y5/2});
        text5.setFillColor(sf::Color::Green);
        //Text6
        sf::Text text6(font, "STATUS", 20);
        float x6 = text6.getGlobalBounds().size.x;
        float y6 = text6.getGlobalBounds().size.y;
        text6.setPosition({950 - x6/2, 50 - y6/2});
        text6.setFillColor(sf::Color::Green);
        //Push
        texts.push_back(text1);
        texts.push_back(text2);
        texts.push_back(text3);
        texts.push_back(text4);
        texts.push_back(text5);
        texts.push_back(text6);
        //Data
        std::vector<Sach> dataOfBookInLibs;
        for(Node* k = danhsach.head; k != NULL; k = k->next)
        {
            dataOfBookInLibs.push_back(k->data);
        }
        //Main loop
        while(window.isOpen())
        {
            while(const std::optional event = window.pollEvent())
            {
                if(event->is<sf::Event::Closed>())
                {
                    window.close();
                }
                else if(auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                {
                    if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    {
                        window.close();
                        isMainWindowTurnOn = false;
                    }
                    if(keyPressed->scancode == sf::Keyboard::Scancode::K)
                    {
                        std::cout << dataOfBookInLibs.size() << endl;
                    }
                }
            }
            window.clear();
            //Draw
            //Vẽ text cho cột và 1 vài đường kẻ
            for(const auto line : lines)
            {
                window.draw(line);
            }
            for(const auto text : texts)
            {
                window.draw(text);
            }
            window.draw(line);
            //Vẽ dữ liệu cho bảng
            //--Tạo vector lưu dữ liệu cho tất cả sách (mỗi sách có 6 text)
            std::vector<sf::Text> drawBooks;
            //Vẽ
            for (int i = 0; i < dataOfBookInLibs.size(); i++)
            {
                Sach book = dataOfBookInLibs[i];
    
                std::vector<std::string> bookInfo = {
                    book.getId(),
                    book.getName(),
                    book.getAuthor(),
                    book.getType(),
                    std::to_string(book.getPrice()),
                    book.getStatus() == 1 ? "Cant" : "Can"};
    
                for (size_t j = 0; j < bookInfo.size(); j++)
                {
                    float jx, jy;
                    sf::Text text(font, bookInfo[j], 15);
                    if(j == 0)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({50 - jx/2, 120 + (float)(i * 20) - jy/2})); // Dịch chuyển từng dòng sách xuống dưới
                        text.setFillColor(sf::Color::White);
                        drawBooks.push_back(text);
                    }
                    if(j == 1)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({200 - jx/2, 120 + (float)(i * 20) - jy/2})); // Dịch chuyển từng dòng sách xuống dưới
                        text.setFillColor(sf::Color::White);
                        drawBooks.push_back(text);
                    }
                    if(j == 2)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({400 - jx/2, 120 + (float)(i * 20) - jy/2})); // Dịch chuyển từng dòng sách xuống dưới
                        text.setFillColor(sf::Color::White);
                        drawBooks.push_back(text);
                    }
                    if(j == 3)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({600 - jx/2, 120 + (float)(i * 20) - jy/2})); // Dịch chuyển từng dòng sách xuống dưới
                        text.setFillColor(sf::Color::White);
                        drawBooks.push_back(text);
                    }
                    if(j == 4)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({800 - jx/2, 120 + (float)(i * 20) - jy/2})); // Dịch chuyển từng dòng sách xuống dưới
                        text.setFillColor(sf::Color::White);
                        drawBooks.push_back(text);
                    }
                    if(j == 5)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({950 - jx/2, 120 + (float)(i * 20) - jy/2})); // Dịch chuyển từng dòng sách xuống dưới
                        text.setFillColor(sf::Color::White);
                        drawBooks.push_back(text);
                    }
                }
            }
            for(auto a : drawBooks)
            {
                window.draw(a);
            }
            window.display();
        }
    }
}
//Luồng 2
void windowPhieuMuon()
{
    while (isLoginSegment)
    {
        continue;
    }
    while (isMainWindowTurnOn)
    {
        continue;
    }
    
    if(isPhieuMuonWindowTurnOn)
    {
        sf::RenderWindow windowPM(sf::VideoMode({1000, 1000}), "Phieu muon", sf::Style::Close || sf::Style::Titlebar);
        //---Init Table-----
        //Line1
        sf::RectangleShape line1(sf::Vector2f(1000, 1));
        line1.setPosition({0, 100});
        line1.setFillColor(sf::Color::Blue);
        //Line2
        sf::RectangleShape line2(sf::Vector2f(1, 100));
        line2.setPosition({100, 0});
        line2.setFillColor(sf::Color::Blue);
        //Line3
        sf::RectangleShape line3(sf::Vector2f(1, 100));
        line3.setPosition({250, 0});
        line3.setFillColor(sf::Color::Blue);
        //Line4
        sf::RectangleShape line4(sf::Vector2f(1, 100));
        line4.setPosition({400, 0});
        line4.setFillColor(sf::Color::Blue);
        //Line5
        //Line4
        sf::RectangleShape line5(sf::Vector2f(1, 100));
        line5.setPosition({500, 0});
        line5.setFillColor(sf::Color::Blue);
        //Text1
        sf::Font font;
        if(!font.openFromFile("Arial.ttf"))
        {
            std::cout << "Can't load font" << std::endl;
            return;
        }
        sf::Text text1(font, "ID", 20);
        float x1 = text1.getGlobalBounds().size.x;
        float y1 = text1.getGlobalBounds().size.y;
        text1.setPosition({50 - x1/2, 50 - y1/2});
        //Text2
        sf::Text text2(font, "NGAY MUON", 20);
        float x2 = text2.getGlobalBounds().size.x;
        float y2 = text2.getGlobalBounds().size.y;
        text2.setPosition({175 - x2/2, 50 - y2/2});
        //Text3
        sf::Text text3(font, "NGAY TRA", 20);
        float x3 = text3.getGlobalBounds().size.x;
        float y3 = text3.getGlobalBounds().size.y;
        text3.setPosition({325 - x3/2, 50 - y3/2});
        //Text4
        sf::Text text4(font, "STATUS", 20);
        float x4 = text4.getGlobalBounds().size.x;
        float y4 = text4.getGlobalBounds().size.y;
        text4.setPosition({450 - x4/2, 50 - y4/2});
        //Text5
        sf::Text text5(font, "LIST ID", 20);
        float x5 = text5.getGlobalBounds().size.x;
        float y5 = text5.getGlobalBounds().size.y;
        text5.setPosition({750 - x5/2, 50 - y5/2});
        //Vector
        std::vector<sf::RectangleShape> lines;
        std::vector<sf::Text> texts;
        //Push
        lines.push_back(line1);
        lines.push_back(line2);
        lines.push_back(line3);
        lines.push_back(line4);
        lines.push_back(line5);
        texts.push_back(text1);
        texts.push_back(text2);
        texts.push_back(text3);
        texts.push_back(text4);
        texts.push_back(text5);
        //Main loop
        while(windowPM.isOpen())
        {
            while(const std::optional event = windowPM.pollEvent())
            {
                if(event->is<sf::Event::Closed>())
                {
                    windowPM.close();
                    isPhieuMuonWindowTurnOn = false;
                }
            }
            windowPM.clear();
            //Draw
            for(const auto line : lines)
            {
                windowPM.draw(line);
            }
            for(const auto text : texts)
            {
                windowPM.draw(text);
            }
            //Data
            std::vector<sf::Text> drawPhieuMuon;
            for (int i = 0; i < listPhieuMuon.size(); i++)
            {
                PhieuMuon phieuMuon = listPhieuMuon[i];
                std::vector<std::string> phieuMuonInfo = {
                    phieuMuon.getID(),
                    phieuMuon.getNgayMuon(),
                    phieuMuon.getNgayTra(),
                    phieuMuon.getStatus() == 1 ? "NO" : "YES",
                    ""};

                for (auto idSach : phieuMuon.listIdSach)
                {
                    phieuMuonInfo[4] += idSach + " ";
                }

                for (size_t j = 0; j < phieuMuonInfo.size(); j++)
                {
                    float jx, jy;
                    sf::Text text(font, phieuMuonInfo[j], 15);
                    if (j == 0)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({50 - jx / 2, 120 + (float)(i * 20) - jy / 2}));
                        text.setFillColor(sf::Color::White);
                        drawPhieuMuon.push_back(text);
                    }
                    if (j == 1)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({175 - jx / 2, 120 + (float)(i * 20) - jy / 2}));
                        text.setFillColor(sf::Color::White);
                        drawPhieuMuon.push_back(text);
                    }
                    if (j == 2)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({325 - jx / 2, 120 + (float)(i * 20) - jy / 2}));
                        text.setFillColor(sf::Color::White);
                        drawPhieuMuon.push_back(text);
                    }
                    if (j == 3)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({450 - jx / 2, 120 + (float)(i * 20) - jy / 2}));
                        text.setFillColor(sf::Color::White);
                        drawPhieuMuon.push_back(text);
                    }
                    if (j == 4)
                    {
                        jx = text.getGlobalBounds().size.x;
                        jy = text.getGlobalBounds().size.y;
                        text.setPosition(sf::Vector2f({750 - jx / 2, 120 + (float)(i * 20) - jy / 2}));
                        text.setFillColor(sf::Color::White);
                        drawPhieuMuon.push_back(text);
                    }
                }
            }
            for (auto a : drawPhieuMuon)
            {
                windowPM.draw(a);
            }
            windowPM.display();
        }
    }
}
//Luồng 4
void menu1()
{
    while(isLoginSegment == true)
    {
        continue;
    }
    if(isInMenu1 == true)
    {
        cout << "LIST ID in Lib: ";
        for(Node* k = danhsach.head; k != NULL; k = k->next)
        {
            cout << k->data.getId() << " ";
        }
        cout << endl;
        do
        {
            cout << endl;
            cout << "____MENU____" << endl;
            cout << "1.Muon Sach" << endl;
            cout << "2.Tra sach" << endl;
            cout << "3.Danh sach phieu muon" << endl;
            cout << "4.Tim sach theo the loai" << endl;
            cout << "5.Tim sach theo ten sach" << endl;
            cout << "6.Clear all data" << endl;
            cout << "7.So sach da muon" << endl;
            cout << "8.Ket thuc chuong trinh" << endl;
            cout << "Nhap lua chon: ";
            cin >> choice;
            switch (choice)
            {
                case 0:
                {
                    int x;
                    cout << "Nhap so luong sach muon them: "; cin >> x;
                    for(int i = 0; i < x; i++)
                    {
                        Sach sach;
                        sach.nhap();
                        std::lock_guard<std::mutex> lock(mtx);
                        addBookToList(danhsach, sach);
                    }
                    //Ghi ra file
                    for(Node* k = danhsach.head; k != NULL; k = k->next)
                    {
                        oFile.open("..\\Data\\thuviensach.txt", ios::app);
                        oFile << k->data.getId() << endl;
                        oFile << k->data.getName() << endl;
                        oFile << k->data.getAuthor() << endl;
                        oFile << k->data.getType() << endl;
                        oFile << k->data.getPrice() << endl;
                        oFile << k->data.getStatus() << endl;
                        oFile.close();
                    }
                    break;
                }
                case 1:
                {
                    PhieuMuon phieuMuon;
                    int x;
                    cout << "Nhap so luong sach muon muon: "; cin >> x;
                    cin.ignore();
                    std::vector<string> listIdSach;
                    for(int i = 0; i < x; i++)
                    {
                        cout << "Nhap id sach thu " << i + 1 << ": "; 
                        string id;
                        getline(cin, id);
                        listIdSach.push_back(id);
                    }
                    for(auto test : listIdSach)
                    {
                        cout << test << " ";
                    }
                    cout << endl;
                    //Kiem tra xem co sach do trong list khong
                    bool isChecked = true;
                    for(auto idSach : listIdSach)
                    {
                        if(isHaveBook(danhsach, idSach) == false)
                        {
                            isChecked = false;
                        }
                    }
                    if(isChecked == false)
                    {
                        cout << "Khong co sach trong thu vien" << endl;
                        break;
                        cout << "AAAAAA" << endl;
                    }
                    phieuMuon.listIdSach = listIdSach;
                    phieuMuon.nhap();
                    listPhieuMuon.push_back(phieuMuon);
                    for(auto idSach : listIdSach)
                    {
                        changeStatus(danhsach, idSach);
                    }
                    cout << "Muon sach va tao phieu muon thanh cong(Xem trong file sachdamuon.txt)" << endl;
                    soSachDaMuon ++;
                    //Ghi ra file sachdamuon.txt danh sách các phiếu mượn
                    oFile.open("..\\Data\\sachdamuon.txt", ios::app);
                    oFile << phieuMuon.getID() << endl;
                    oFile << phieuMuon.getNgayMuon() << endl;
                    oFile << phieuMuon.getNgayTra() << endl;
                    oFile << phieuMuon.getStatus() << endl;
                    for(auto idSach : listIdSach)
                    {
                        oFile << idSach << endl;
                    }
                    oFile.close();
                    //Cập nhật lại thông tin các sách vào thuviensach(do thay đổi status của sách)
                    oFile.open("..\\Data\\thuviensach.txt", ios::trunc);
                    for(Node* k = danhsach.head; k != NULL; k = k->next)
                    {
                        oFile << k->data.getId() << endl;
                        oFile << k->data.getName() << endl;
                        oFile << k->data.getAuthor() << endl;
                        oFile << k->data.getType() << endl;
                        oFile << k->data.getPrice() << endl;
                        oFile << k->data.getStatus() << endl;
                    }
                    oFile.close();
                    break;
                }
                case 2:
                {
                    string id;
                    cin.ignore();
                    cout << "Nhap id phieu da muon: "; getline(cin, id);
                    std::lock_guard<std::mutex> lock(mtx);
                    for(auto phieumuon : listPhieuMuon)
                    {
                        if(phieumuon.getID() == id)
                        {
                            for(auto idSach : phieumuon.listIdSach)
                            {
                                changeStatus(danhsach, idSach);
                            }
                            cout << "Tra sach thanh cong" << endl;
                            phieumuon.setStatus(0);
                            break;
                        }
                    }
                    break;
                }
                case 3:
                {
                    isPhieuMuonWindowTurnOn = true;
                    isMainWindowTurnOn = false;
                    break;
                }
                case 4:
                {
                    isSearchWindowTurnOn = true;
                    break;
                }
                case 5:
                {
                    isSearchWindowTurnOn = true;
                    break;
                }
                case 6:
                {
                    oFile.open("..\\Data\\thuviensach.txt", ios::trunc);
                    oFile.clear();
                    oFile.close();
                    break;
                }
                case 7:
                {
                    cout << "Tong so phieu muon la: " << soSachDaMuon << endl;
                    break;
                }
                case 8:
                {
                    cout << "Ket thuc chuong trinh" << endl;
                    break;
                }
                default:
                    cout << "Lua chon khong hop le" << endl;
                    break;
            }
        } while(choice != 8);
    }
}
//Luồng 3
void searchWindow()
{
    sf::RenderWindow searchWindow(sf::VideoMode({1000, 1000}), "SEARCH RESULT", sf::Style::Close || sf::Style::Titlebar);

    //Font
    sf::Font font;
    if(!font.openFromFile("Arial.ttf"))
    {
        std::cout << "Can't load font" << std::endl;
        return;
    }
    std::vector<sf::RectangleShape> lines;
    //Line
    sf::RectangleShape line(sf::Vector2f(1000, 1));
    line.setPosition({0, 100});
    line.setFillColor(sf::Color::Blue);
    //Line1
    sf::RectangleShape line1(sf::Vector2f(1, 100));
    line1.setPosition({100, 0});
    line1.setFillColor(sf::Color::Blue);
    //Line2
    sf::RectangleShape line2(sf::Vector2f(1, 100));
    line2.setPosition({300, 0});
    line2.setFillColor(sf::Color::Blue);
    //Line3
    sf::RectangleShape line3(sf::Vector2f(1, 100));
    line3.setPosition({500, 0});
    line3.setFillColor(sf::Color::Blue);
    //Line4
    sf::RectangleShape line4(sf::Vector2f(1, 100));
    line4.setPosition({700, 0});
    line4.setFillColor(sf::Color::Blue);
    //Line5
    sf::RectangleShape line5(sf::Vector2f(1, 100));
    line5.setPosition({900, 0});
    line5.setFillColor(sf::Color::Blue);
    //Push
    lines.push_back(line1);
    lines.push_back(line2);
    lines.push_back(line3);
    lines.push_back(line4);
    lines.push_back(line5);
    //Vector text
    std::vector<sf::Text> texts;
    //Text1
    sf::Text text1(font, "ID", 20);
    float x1 = text1.getGlobalBounds().size.x;
    float y1 = text1.getGlobalBounds().size.y;
    text1.setPosition({50 - x1/2, 50 - y1/2});
    //Text2
    sf::Text text2(font, "NAME", 20);
    float x2 = text2.getGlobalBounds().size.x;
    float y2 = text2.getGlobalBounds().size.y;
    text2.setPosition({200 - x2/2, 50 - y2/2});
    //Text3
    sf::Text text3(font, "AUTHOR", 20);
    float x3 = text3.getGlobalBounds().size.x;
    float y3 = text3.getGlobalBounds().size.y;
    text3.setPosition({400 - x3/2, 50 - y3/2});
    //Text4
    sf::Text text4(font, "TYPE", 20);
    float x4 = text4.getGlobalBounds().size.x;
    float y4 = text4.getGlobalBounds().size.y;
    text4.setPosition({600 - x1/2, 50 - y1/2});
    //Text5
    sf::Text text5(font, "PRICE", 20);
    float x5 = text5.getGlobalBounds().size.x;
    float y5 = text5.getGlobalBounds().size.y;
    text5.setPosition({800 - x5/2, 50 - y5/2});
    //Text6
    sf::Text text6(font, "STATUS", 20);
    float x6 = text6.getGlobalBounds().size.x;
    float y6 = text6.getGlobalBounds().size.y;
    text6.setPosition({950 - x6/2, 50 - y6/2});
    //Push
    texts.push_back(text1);
    texts.push_back(text2);
    texts.push_back(text3);
    texts.push_back(text4);
    texts.push_back(text5);
    texts.push_back(text6);
    //Main loop
    while(searchWindow.isOpen())
    {
        while(const std::optional event = searchWindow.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                searchWindow.close();
                isMainWindowTurnOn = true;
            }
            else if(auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    searchWindow.close();
                    isMainWindowTurnOn = true;
                }
            }
        }
        if(isSearchWindowTurnOn == false)
        {
            searchWindow.setVisible(false);
        }
        else if(isSearchWindowTurnOn == true)
        {
            searchWindow.setVisible(true);
        }
        searchWindow.clear();
        //Draw
        for(const auto line : lines)
        {
            searchWindow.draw(line);
        }
        for(const auto text : texts)
        {
            searchWindow.draw(text);
        }
        searchWindow.draw(line);
        searchWindow.display();
    }
}
//Luồng 5
void menu2()
{
    while(isLoginSegment == true)
    {
        continue;
    }
    if(isInMenu1 == false)
    {
        do
        {
            cout << "____MENU____" << endl;
            cout << "1.Them Sach" << endl;
            cout << "2.Xoa Sach" << endl;
            cout << "3.Ket thuc chuong trinh" << endl;
            cout << "Nhap lua chon: ";
            cin >> choice;
            switch (choice)
            {
                case 1:
                {
                    int x;
                    cout << "Nhap so luong sach muon them: "; cin >> x;
                    for(int i = 0; i < x; i++)
                    {
                        cin.ignore();
                        Sach sach;
                        sach.nhap();
                        std::lock_guard<std::mutex> lock(mtx);
                        if(isHaveThisIdInList(danhsach, sach.getId()))
                        {
                            cout << "KHONG THE TRUNG ID" << endl;
                            break;
                        }
                        addBookToList(danhsach, sach);
                        cout << "Them thanh cong" << endl;
                    }
                    //Ghi ra file
                    oFile.open("..\\Data\\thuviensach.txt", ios::trunc);
                    oFile.clear();
                    for(Node* k = danhsach.head; k != NULL; k = k->next)
                    {
                        oFile << k->data.getId() << endl;
                        oFile << k->data.getName() << endl;
                        oFile << k->data.getAuthor() << endl;
                        oFile << k->data.getType() << endl;
                        oFile << k->data.getPrice() << endl;
                        oFile << k->data.getStatus() << endl;
                    }
                    oFile.close();
                    cout << "Da ghi ra file" << endl;
                    break;
                }
                case 2:
                {
                    string id;
                    cin.ignore();
                    cout << "Nhap id sach muon xoa: "; getline(cin, id);
                    std::lock_guard<std::mutex> lock(mtx);
                    deleteBook(danhsach, id);
                    //Ghi ra file
                    oFile.open("..\\Data\\thuviensach.txt", ios::trunc);
                    oFile.clear();
                    for(Node* k = danhsach.head; k != NULL; k = k->next)
                    {
                        oFile << k->data.getId() << endl;
                        oFile << k->data.getName() << endl;
                        oFile << k->data.getAuthor() << endl;
                        oFile << k->data.getType() << endl;
                        oFile << k->data.getPrice() << endl;
                        oFile << k->data.getStatus() << endl;
                    }
                    oFile.close();
                    break;
                }
                case 3:
                {
                    system("exit");
                    break;
                }
                default:
                    break;
            }
        } while(choice != 3);
    }
}
int main()
{
    //Tải dữ liệu từ file vào danhsach
    iFile.open("..\\Data\\thuviensach.txt");

    while (true)
    {
        string id, name, author, type;
        float price;
        bool status;
        if (!getline(iFile, id)) break;      // Kiểm tra đọc thành công
        if (!getline(iFile, name)) break;
        if (!getline(iFile, author)) break;
        if (!getline(iFile, type)) break;
        if (!(iFile >> price)) break;        // Đọc số float
        if (!(iFile >> status)) break;       // Đọc số bool
        iFile.ignore();
        Sach sach(id, name, author, type, price, status);
        addBookToList(danhsach, sach);
    }
    iFile.close();
    iFile.open("Data\\sachdamuon.txt");
    while(true)
    {
        string id, ngayMuon, ngayTra;
        std::vector<string> listID;
        bool status;
        if (!getline(iFile, id)) break;      // Kiểm tra đọc thành công
        if (!getline(iFile, ngayMuon)) break;
        if (!getline(iFile, ngayTra)) break;
        for(int i = 0; i < soSachDaMuon; i++)
        {
            getline(iFile, listID[i]);
        }
        if (!(iFile >> status)) break;       // Đọc số bool
        iFile.ignore();
        PhieuMuon temp(id, ngayMuon, ngayTra, status, listID);
        listPhieuMuon.push_back(temp);
    }
    
    for(Node* k = danhsach.head; k != NULL; k = k->next)
    {
        count = count + 1;
    }
    std::cout << "So sach trong thu vien: " << count << std::endl;
    oFile.close();
    std::thread t0(loginTerminal);
    std::thread t1(mainWindow);
    std::thread t2(windowPhieuMuon);
    std::thread t3(searchWindow);
    std::thread t4(menu1);
    std::thread t5(menu2);

    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}
