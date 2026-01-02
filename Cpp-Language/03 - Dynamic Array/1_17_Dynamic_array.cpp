/*
1. Define a class DynArray to implement dynamic array data structure with member variables to store capacity of array, 
   last index of the last filled block of the array and a pointer to hold the address of the first block of the dynamically created array.
2. In question 1, define a parameterised constructor to create an array of specified size.
3. In question 1, define a method doubleArray() to increase the size of the array by double of its size.
4. In question 1, define a method halfArray() to decrease the size of the array by half of its size.
5. In question 1, define a method which returns the current capacity of the array.
6. In question 1, add a method to check whether an array is empty or not by returning True or False.
7. In question 1, define a method to append a new element in the array.
8. In question 1, define a method to insert a new element at specified index.
9. In question 1, define a method to edit an element at specified index.
10. In question 1, define a method to delete an element at specified index.
11. In question 1, define a method to check if the array is full by returning true or false.
12. In question 1, define a method to get element at specified index.
13. In question 1, define a method to count number of elements present in the array.
14. In question 1, define a destructor to deallocate the memory of array.
15. In question 1, define a method to find an element in the array. Return index if the element found, otherwise return -1.
16. In question 1, define a copy constructor to implement deep copy.
17. In question 1, define a copy assignment operator to implement deep copy.
*/

#include<stdio.h>
#include<iostream>
using namespace std;
class DynArray //Q1
{
    private:
        int capacity;
        int lastIndex;
        int *p;
    protected:
        void doubleArray(); //Q3
        void halfArray(); //Q4
    public:
        DynArray();
        DynArray(int); //Q2
        DynArray(DynArray&); //Q16
        DynArray& operator=(DynArray&); //Q17
        void createArray(int);
        void insert(int,int); //Q8
        void append(int); //Q7
        int getItem(int); //Q12
        bool isEmpty(); //Q6
        bool isFull(); //Q11
        void del(int); //Q10
        void edit(int,int); //Q9
        int count(); //Q13
        int getCapacity(); //Q5
        void printDynamicArray();
        int searchElement(int); //Q15
        ~DynArray(); //Q14
};
DynArray::DynArray()
{
    p=NULL;
}
DynArray::DynArray(int size)
{
    capacity=size;
    p=new int[capacity];
    lastIndex=-1;
}
DynArray::DynArray(DynArray &arr)
{
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    p=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        p[i]=arr.p[i];
}
DynArray& DynArray::operator=(DynArray &arr)
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
void DynArray::createArray(int cap)
{
    capacity=cap;
    lastIndex=-1;  
    if(p!=NULL)
        delete []p; 
    p=new int[capacity];
}
void DynArray::doubleArray()
{
    int *temp,i;
    temp=new int[capacity*2];
    for(i=0;i<=lastIndex;i++)
        temp[i]=p[i];
    delete []p;
    p=temp;
    capacity*=2;
}
void DynArray::halfArray()
{
    int *temp,i;
    temp=new int[capacity/2];
    for(i=0;i<=lastIndex;i++)
        temp[i]=p[i];
    delete []p;
    p=temp;
    capacity/=2;
}
void DynArray::insert(int index,int data)
{
    try
    {
        if(index<0 || index>=lastIndex+2)
            throw 1;
        if(isFull())
            doubleArray();
        for(int i=lastIndex;i>=index;i--)
            p[i+1]=p[i];
        p[index]=data;
        lastIndex++;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"Invalid Index";
    }
}
void DynArray::append(int data)
{
    if(isFull())
        doubleArray();
    lastIndex++;
    p[lastIndex]=data;
}
int DynArray::getItem(int index)
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
bool DynArray::isFull()
{
    return lastIndex==(capacity-1);
}
bool DynArray::isEmpty()
{
    return lastIndex==-1;
}
void DynArray::del(int index)
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
        if(capacity && lastIndex<capacity/2)
            halfArray();
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\nInvalid Index or Underflow.";
        if(e==2)
            cout<<"\nArray is Empty.";
    }
}
void DynArray::edit(int index,int newData)
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
int DynArray::count()
{
    return lastIndex+1;
}
int DynArray::getCapacity()
{
    return capacity;
}
void DynArray::printDynamicArray()
{
    for(int i=0;i<=lastIndex;i++)
        cout<<p[i]<<endl;
}
int DynArray::searchElement(int data)
{
    if(!isEmpty())
    {
        for(int i=0;i<=lastIndex;i++)
            if(p[i]==data)
                return i;
    }
    else
    {
        cout<<"Array is empty henced element not found.";
    }
    return -1;
}
DynArray::~DynArray()
{
    delete []p;
}
int main()
{
    return 0;
}