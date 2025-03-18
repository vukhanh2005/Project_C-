#include "..\\include\\ListBookInLibrary.h"


Node* createNode(Sach data)
{
    Node* p = new Node();
    p->data = data;
    p->next = NULL;
    return p;
}
void addBookToList(ListBook& list, Sach data)
{
    Node* p = createNode(data);
    if (list.head == NULL)
    {
        list.head = list.tail = p;
    }
    else
    {
        list.tail->next = p;
        list.tail = p;
    }
}
void showListBook(ListBook list)
{
    Node* p = list.head;
    while (p != NULL)
    {
        cout << p->data.getId() << " " << p->data.getName() << " " << p->data.getAuthor() << " " << p->data.getType() << " " << p->data.getStatus() << " " << p->data.getPrice() << " " << endl;
        p = p->next;
    }
}
void deleteBook(ListBook& list, string id)
{
    Node* p = list.head;
    Node* prev = NULL;
    while (p != NULL)
    {
        if (p->data.getId() == id)
        {
            if (p == list.head)
            {
                list.head = list.head->next;
                delete p;
                return;
            }
            else if (p == list.tail)
            {
                list.tail = prev;
                prev->next = NULL;
                delete p;
                return;
            }
            else
            {
                prev->next = p->next;
                delete p;
                return;
            }
        }
        prev = p;
        p = p->next;
    }
}
bool isHaveBook(ListBook list, string id)
{
    for(Node* k = list.head; k != NULL; k = k->next)
    {
        if(k->data.getId() == id)
        {
            return true;
        }
        else return false;
    }
}
void changeStatus(ListBook& list, string id)
{
    for(Node* k = list.head; k != NULL; k = k->next)
    {
        if(k->data.getId() == id)
        {
            k->data.setStatus(!k->data.getStatus());
        }
    }
}