/*
1. Define a class DLL to implement Doubly Linked list data structure with member variable start pointer of type node.
2. In question 1, define a constructor to initialise start pointer with NULL.
3. In question 1, define a method to insert a data into the list at the beginning.
4. In question 1, define a method to insert a data into the list at the end.
5. In question 1, define a method to search a node with the given item.
6. In question 1, define a method to insert a data into the list after the specified node of the list.
7. In question 1, define a method to delete first node from the list.
8. In question 1, define a method to delete last node of the list.
9. In question 1, define a method to delete a specific node.
10. In question 1, define a destructor to deallocates memory for all the nodes in the linked list.
11. In question 1, define a copy constructor to implement deep copy.
12. In question 1, define a copy assignment operator to implement deep copy.
*/

#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};
class DLL //Q1
{
    private:
        node *start;
    public:
        DLL(); //Q2
        DLL(DLL&); //Q11
        DLL& operator=(DLL&); //Q12
        void insertAtFirst(int); //Q3
        void insertAtLast(int); // Q4
        node* search(int); //Q5
        void insertAfter(node*,int); //Q6
        void deleteFirst(); //Q7
        void deleteLast(); //Q8
        void del(node*); //Q9
        ~DLL(); //Q10
};
DLL::DLL()
{
    start=NULL;
}
DLL::DLL(DLL &d)
{
    node *t;
    if(d.start!=NULL)
    {
        while(t->next!=NULL)
            t=t->next;
        while(t)
        {
            insertAtFirst(t->item);
            t=t->prev;
        }
    }
    else
    {
        start=NULL;
    }
}
DLL& DLL::operator=(DLL&d)
{
    while(start)
        deleteFirst();
    node *t;
    if(d.start!=NULL)
    {
        while(t->next!=NULL)
            t=t->next;
        while(t)
        {
            insertAtFirst(t->item);
            t=t->prev;
        }
    }
    else
    {
        start=NULL;
    }
    return *this;
}
void DLL::insertAtFirst(int data)
{
    node *n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=start;
    if(start!=NULL)
        start->prev=n;
    start=n;
}
void DLL::insertAtLast(int data)
{
    node *n=new node;
    node *r;
    r=start;
    n->item=data;
    n->next=NULL;
    if(start)
    {
        while(r->next!=NULL)
            r=r->next;
        n->prev=r;
        r->next=n;
    }
    else
    {
        n->prev=NULL;
        start=n;
    }
}
node* DLL::search(int data)
{
    node *t;
    t=start;
    while(t)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
void DLL::insertAfter(node *t,int data)
{
    node *n;
    n=new node;
    n->prev=t;
    n->item=data;
    n->next=t->next;
    if(t->next!=NULL)
        t->next->prev=n;
    t->next=n;
}
void DLL::deleteFirst()
{
    node *r;
    if(start!=NULL)
    {
        r=start;
        start=r->next;
        start->prev=NULL;
        delete r;
    }
}
void DLL::deleteLast()
{
    node *t;
    t=start;
    if(start==NULL)
    {
        cout<<"List Underflow.";
    }
    else
    {
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else
        {
            t=start;
            while(t->next!=NULL)
                t=t->next;
            t->prev->next=NULL;
            delete t;
        }
    }
}
void DLL::del(node *t)
{
    if(start==NULL)
        cout<<"List Underflow.";
    else if(start==t)
        deleteFirst();
    else if(t->next==NULL)
        deleteLast();
    else
    {
        t->next->prev=t->prev;
        t->prev->next=t->next;
        delete t;
    }
}
DLL::~DLL()
{
    while(start)
        deleteFirst();
}
