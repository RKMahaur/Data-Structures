/*
1. Define a class SLL to implement singly linked list data structure with member variable start pointer of type node.
2. In question 1, define a constructor to initialise start pointer with NULL.
3. In question 1, define a method to insert a data into the list at the beginning.
4. In question 1, define a method to insert a data into the list at the end
5. In question 1, define a method to search a node with the give item.
6. In question 1, define a method to insert a data into the list after the specified node of the list.
7. In question 1, define a method to delete first node from the list.
8. In question 1. define a method to delete last node of the list.
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
class SLL //Q1
{
    private:
        node *start;
    public:
        SLL(); //Q2
        SLL(SLL&); //Q11
        SLL& operator=(SLL&); //Q12
        void insertAtStart(int); //Q3
        void insertAtLast(int); //Q4
        node* search(int); //Q5
        void insertAfter(node*,int); //Q6
        void deleteFirst(); //Q7
        void deleteLast(); //Q8
        void deleteNode(node*); //Q9
        ~SLL(); //Q10
};
SLL::SLL()
{
    start=NULL;
}
SLL::SLL(SLL &list)
{
    node *t;
    t=list.start;
    start=NULL;
    while(t)
    {
        insertAtLast(t->item);
        t=t->next;
    }
}
SLL& SLL::operator=(SLL &list)
{
    node *t;
    t=list.start;
    while(start)
        deleteFirst();
    while(t)
    {
        insertAtLast(t->item);
        t=t->next;
    } 
    return (*this);
}
void SLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
void SLL::insertAtLast(int data)
{
    node *t;
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }
}
node* SLL::search(int data)
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
void SLL::insertAfter(node *t,int data)
{
    node *n;
    if(t)
    {
        n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}
void SLL::deleteFirst()
{
    node *n;
    if(start)
    {
        n=start;
        start=n->next;
        delete n;
    }
    else
    {
        cout<<"List is already Empty.";
    }
}
void SLL::deleteLast()
{
    node *t;
    try
    {
        if(start==NULL)
            throw 1;
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else
        {
            t=start;
            while(t->next->next!=NULL)
                t=t->next;
            delete t->next;
            t->next=NULL;
        }
    }
    catch(int e)
    {}
}
void SLL::deleteNode(node *t)
{
    node *r;
    try
    {
        if(start==NULL)
            throw 1;
        if(start==t)
            deleteFirst();
        else
        {
            r=start;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
                delete t;
        }
    }
    catch(int e)
    {}
}
SLL::~SLL()
{
    while(start)
        deleteFirst();
}