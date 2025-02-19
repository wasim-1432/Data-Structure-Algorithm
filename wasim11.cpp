#include<iostream>
using namespace std;
class Array
{
    private:     //A class Array to implement array data structure with member variables to store capacity of array ,last index of the last filled block of the array and a pointer to hold the address of the first block of dynamically created array
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int);
        bool is_Empty();
        void append(int data);
        void showData();
        void insert(int,int);
        void edit(int ,int);
        void del(int);
        bool isFull();
        void count();
        void findelement(int);
        void getValue(int);
        ~Array();
};
Array::Array(int cap)     //Define a parametrised constructor to create an array of specified size.
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
bool Array::is_Empty()     //To cehck whether an array is empty or not by returning true or false.
{
    if(lastIndex==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Array::append(int data)       //A method to append a new element in the array
{
    if(lastIndex==capacity-1)
    {
        cout<<"OverFlow"<<endl;
    }
    else
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
}
void Array::showData()         //To show the data
{
    int index;
    for(index=0;index<=lastIndex;index++)
    {
        cout<<ptr[index]<<" ";
    }
    cout<<"\n";
}
void Array::insert(int index,int data)    // A method to insert a new element at specified index.
{
    if(lastIndex==capacity-1)
    {
        cout<<"Stack is already full,You can not add any element"<<endl;
    }
    else
    {
        int i;
        lastIndex++;
        for(i=lastIndex;i>=index;i--)
        {
            ptr[i+1]=ptr[i];
        }
        ptr[i+1]=data;
    }
}
void Array::edit(int index,int data)    //A method to edit an element at specified index
{
    if(index<0 || index>lastIndex)
    {
        cout<<"Not edited"<<endl;
    }
    else
    {
        ptr[index]=data;
    }
}
void Array::del(int index)         //A method to delete an element at specified index.
{
    if(index<0 || index>lastIndex)
    {
        cout<<"Not Deleted"<<endl;
    }
    else
    {
        int i;
        for(i=index;i<lastIndex;i++)
        {
            ptr[i]=ptr[i+1];
        }
        lastIndex--;
    }
}
bool Array::isFull()        //A method to check if the array is full by retuning true or false.
{
    if(lastIndex==capacity-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Array::count()     //A method to count number of elements present in the array
{
    cout<<"\nTotal elements in the array="<<lastIndex+1;
}
void Array::findelement(int data)    //A method to find an element in the array.
{
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        if(ptr[i]==data)
        {
            cout<<"\nFound";
            break;
        }
    }
    if(ptr[i]!=data)
    {
        cout<<"\nNot Found";
    }
}
void Array::getValue(int index)    //A method to get element at specified index.
{
    if(index<0 || index>lastIndex+1)
    {
        cout<<"Invalid Index\n";
    }
    else
    {
        cout<<ptr[index];
    }
}
Array::~Array()       //A destructor to deallocate the memory of the array
{
    delete []ptr;
}
int main()
{
    Array arr(30);
    arr.append(44);
    arr.append(55);
    arr.append(66);
    arr.append(11);
    arr.append(12);
    arr.insert(5,88);
    arr.edit(4,99);
    arr.del(0);
    arr.append(76);
    arr.showData();
    arr.getValue(2);
    arr.findelement(55);
    arr.count();
    arr.isFull();
    cout<<endl;
    return 0;
}