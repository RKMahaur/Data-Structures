/*
1. Define a class CLL to implement Circular Linked list data structure with member variable last pointer of type node.
2. In question 1, define a constructor to initialise last pointer with NULL.
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
    int item;
    node *next;
};
class CLL //Q1
{
    private:
        node *last;
    public:
        CLL(); //Q2
        CLL(CLL&); //Q11
        CLL& operator=(CLL&); //Q12
        void insertAtStart(int);//Q3
        void insertAtLast(int); //Q4
        node *search(int); //Q5
        void insert(node*,int); //Q6
        void deleteFirst(); //Q7
        void deleteLast(); //Q8
        void del(node*); //Q9
        ~CLL(); //Q10
};
CLL::CLL()
{
    last=NULL;
}
CLL::CLL(CLL &c)
{
    node *t;
    if(c.last==NULL)
        last==NULL;
    else
    {
        t=c.last->next;
        while(t!=c.last)
        {
            insertAtLast(t->item);
            t->next;
        }
        insertAtLast(t->item);
    }
}
CLL& CLL::operator=(CLL &c)
{
    while(last)
        deleteFirst();
    node *t;
    if(c.last==NULL)
        last==NULL;
    else
    {
        t=c.last->next;
        while(t!=c.last)
        {
            insertAtLast(t->item);
            t->next;
        }
        insertAtLast(t->item);
    }
    return *this;
}
void CLL::insertAtStart(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void CLL::insertAtLast(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
node* CLL::search(int data)
{
    node *t;
    if(last==NULL)
        return NULL;
    t=last->next;
    while(t!=last)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    if(last->item==data)
        return last;
    return NULL;
}
void CLL::insert(node* t,int data)
{
    node *n;
    if(t==last)
        insertAtLast(data);
    else if(t)
    {
        n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}
void CLL::deleteFirst()
{
    node*r;
    if(last)
    {
        r=last->next;
        last->next=r->next;
        if(last==r)
            last==NULL;
        delete r;
    }
}
void CLL::deleteLast()
{
    node *r,*t;
    if(last)
    {
        r=last;
        if(r->next==r)
            last==NULL;
        else    
        {
            t=last->next;
            while(t->next!=last)
                t=t->next;
            t->next=last->next;
            last=t;
        }
        delete r;
    }
}
void CLL::del(node *t)
{
    node *r;
    if(t!=NULL)
    {
        if(t==last)
            deleteLast();
        else if(t==last->next)
            deleteFirst();
        else
        {
            r=last->next;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete t;
        }
    }
}
CLL::~CLL()
{
    while(last)
        deleteFirst();
}

