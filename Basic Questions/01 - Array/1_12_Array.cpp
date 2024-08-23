/*
1. Define a class Array to implement array data structure with member variables to store capacity of array, last index of the last filled 
   block of the array and a pointer to hold the address of the first block of the dynamically created array.
2. In the question 1, define a parameterised constructor to create an array of specified size.
3. In the question 1, add a method to check whether an array is empty or not by returning True or False.
4. In the question 1, define a method to append a new element in the array.
5. In the question 1, define a method to insert a new element in the array.
6. In the question 1, define a method to edit an element at specified index.
7. In the question 1, define a method to delete an element at specified index.
8. In the question 1, define a method to check is the array is full by returning true or false.
9. In the question 1, define a method to get element at specified index.
10. In the question 1, define a method to count number of elements present in the array.
11. In the question 1, define a destructor to deallocate the memory of array.
12. In the question 1, define a method to find an element in the array. Return index if the element found, otherwise return -1.
*/

#include<stdio.h>
#include<iostream>
using namespace std;
class Array //Q1
{
    private:
        int capacity;
        int lastIndex;
        int *p;
    public:
        Array();
        Array(int); //Q2
        Array(Array&);
        Array& operator=(Array&);
        void createArray(int);
        void insert(int,int); //Q5
        void append(int); //Q4
        int getItem(int); //Q9
        bool isEmpty(); //Q3
        bool isFull(); //Q8
        void del(int); //Q7
        void edit(int,int); //Q6
        int count(); //Q10
        int getCapacity();
        int findItem(int); //Q12
        ~Array(); //Q11
};
Array::Array()
{
    p=NULL;
}
Array::Array(int size)
{
    capacity=size;
    p=new int[capacity];
    lastIndex=-1;
}
Array::Array(Array &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    p=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        p[i]=arr.p[i];
}
Array& Array::operator=(Array &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(p!=NULL)
        delete []p;
    p=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        p[i]=arr.p[i];
    return (*this);
}
void Array::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;  
    if(p!=NULL)
        delete []p; 
    p=new int[capacity];
}
void Array::insert(int index,int data)
{
    int i;
    try
    {
        if(index<0 || index>lastIndex+1)
            throw 1;
        if(isFull())
            throw 2;
        for(i=lastIndex;i>=index;i--)
            p[i+1]=p[i];
        p[index]=data;
        lastIndex++;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Invalid Index";
        else if((e==2))
            cout<<"Overflow.";
    }  
}
void Array::append(int data)
{
    if(!isFull())
    {
        lastIndex++;
        p[lastIndex]=data;
    }
    else
        cout<<"Overflow: append not possible as array is full."<<endl;
}
int Array::getItem(int index)
{
    try
    {
        if(index<0 || index>lastIndex)
            throw 1;
        return p[index];
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\nInvalid Index or Array is empty";
    }
    return -1;
}
bool Array::isFull()
{
    return lastIndex==(capacity-1);
}
bool Array::isEmpty()
{
    return lastIndex==-1;
}
void Array::del(int index)
{
    int i;
    try
    {
        if(index<0 || index>lastIndex)
            throw 1;
        else if(isEmpty())
            throw 2;
        for(i=index;i<=lastIndex-1;i++)
            p[i]=p[i+1];
        lastIndex--;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\nInvalid Index or Underflow.";
        if(e==2)
            cout<<"\nArray is Empty.";
    }
}
void Array::edit(int index,int newData)
{
    try
    {
        if(index<0 || index>lastIndex)
            throw 1;
        p[index]=newData;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\nInvalid Index or Array is empty";
    }
}
int Array::count()
{
    return lastIndex+1;
}
int Array::getCapacity()
{
    return capacity;
}
Array::~Array()
{
    delete []p;
}
int Array::findItem(int data)
{
    if(!isFull())
    {
        for(int i=0;i<=lastIndex;i++)
            if(p[i]==data)
                return i;
        return -1;
    }
    else
    {
        cout<<"Array is empty henced element not found.";
    }
}

