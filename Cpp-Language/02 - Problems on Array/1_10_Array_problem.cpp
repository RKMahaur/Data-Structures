/*
1. Define a function to sort elements of the array.
2. Define a function to find the greatest element in the array.
3. Define a function to find the smallest element in the array.
4. Define a function to search an element in the array.
5. Define a function to calculate sum of all the elements of an array.
6. Define a function to calculate average of all the elements of an array.
7. Define a function to rotate an array towards right by one position.
8. Define a function to remove duplicate elements in the array.
9. Define a function to find the second largest element in the array.
10. Define a function to swap elements with specified indices in the array.
*/

#include<stdio.h>
#include<iostream>
using namespace std;
class Array
{
    private:
        int capacity;
        int lastIndex;
        int *p;
    public:
        Array();
        Array(int);
        Array(Array&);
        Array& operator=(Array&);
        void createArray(int);
        void insert(int,int);
        void append(int);
        int getItem(int);
        bool isEmpty();
        bool isFull();
        void del(int);
        void edit(int,int);
        int count();
        int getCapacity();
        int findItem(int);
        ~Array();
        // solution of Assignment
        void sortArray(); //Q1
        int findGreatest(); //Q2
        int findSmallest(); //Q3
        int searchElement(int); //Q4
        int sumArray(); //Q5
        float findAverage(); //Q6
        void rotate(); //Q7
        void removeDuplicate(); //Q8
        int findSecondLarge(); //Q9
        void swap(int,int); //Q10
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
int Array::findItem(int data)
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
Array::~Array()
{
    delete []p;
}
void Array::sortArray()
{
    int i,r,temp;
    if(!isEmpty())
    {
        for(r=1;r<=lastIndex;r++)
        {
            for(i=0;i<=lastIndex-r;i++)
            {
                if(p[i]>p[i+1])
                {
                    temp=p[i];
                    p[i]=p[i+1];
                    p[i+1]=temp;
                }
            }
        }
        cout<<"\nArray is Sorted."<<endl;
    }
    else
    {
        cout<<"Array is already empty.";
    }
}
int Array::findGreatest()
{
    int max,i;
    if(!isEmpty())
    {
        max=p[0];
        for(i=1;i<=lastIndex;i++)
        {
            if(p[i]>max)
            max=p[i];
        }
        return max;
    }
    else
    {
        cout<<"Array is already empty.";
    }
    return 0;
}
int Array::findSmallest()
{
    int small,i;
    if(!isEmpty())
    {
        small=p[0];
        for(i=1;i<=lastIndex;i++)
        {
            if(p[i]<small)
            small=p[i];
        }
        return small;
    }
    else
    {
        cout<<"Array is already empty.";
    }
    return -1;
}
int Array::searchElement(int data)
{
    if(!isEmpty())
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
int Array::sumArray()
{
    int i,sum=0;
    if(!isEmpty())
    {
        for(i=0;i<=lastIndex;i++)
            sum=sum+p[i];
        return sum;
    }
    else
    {
        cout<<"Array is already empty.";
    }
    return 0;
}
float Array::findAverage()
{
    float avg;
    avg=sumArray()/count();
    return avg;
}
void Array::rotate()
{
    int n,i;
    if(!isEmpty())
    {
        n=p[lastIndex];
        for(i=lastIndex;i>0;i++)
            p[i]=p[i-1];
        p[0]=n;
    }
    else
    {
        cout<<"Array is Empty.";
    }
}
void Array::removeDuplicate()
{
    sortArray();
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        while(p[i]==p[i+1])
        {
            del(i+1);
        }
    }
}
int Array::findSecondLarge()
{
    int max,sec_max;
    if(p[0]>p[1])
    {
        max=p[0];
        sec_max=p[1];
    }
    else
    {
        sec_max=p[0];
        max=p[1];
    }
    for(int i=2;i<=lastIndex;i++)
    {
        if(p[i]>max)
        {
            sec_max=max;
            max=p[i];
        }
        else
        {
            if(p[i]>sec_max)
                sec_max=p[i];
        }
    }
    return sec_max;
}
void Array::swap(int i1,int i2)
{
    int t,i;
    try
    {
        if((i1<0 || i1>lastIndex)&&(i2<0 || i2>lastIndex))
            throw 1;
        t=p[i1];
        p[i1]=p[i2];
        p[i2]=t;
    }
    catch(int e)
    {
        cout<<"Invalid Index.";
    }
}