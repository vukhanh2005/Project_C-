#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "..\\include\\Sach.h"
using namespace std;

class Node
{
    public:
        Sach data;
        Node *next;
};
class ListBook
{
    public:
        Node* head = NULL;
        Node* tail = NULL;
};
Node* createNode(Sach data);
void addBookToList(ListBook& list, Sach data);
void showListBook(ListBook list);
void deleteBook(ListBook& list, string id);
bool isHaveBook(ListBook list, string id);
void changeStatus(ListBook& list, string id);