#include<iostream>
using namespace std;
#define OVERFLOW 1;
#define INVALID_INDEX 2;
class Array
{
    private:
        int capacity;           
        int lastIndex;
        int *ptr;
    public:
        Array(int);
        bool is_Empty();
        void Append(int);
        void ShowData();
        void Insert(int,int);
        void Edit(int,int);
        void del(int);
        bool is_Full();
        int get_Element(int);
        int count_Element();
        ~Array();
        int found(int);
};
Array::Array(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
bool Array::is_Empty()
{
    return lastIndex==-1;
}
void Array::Append(int data)
{
    if(lastIndex==capacity-1)
    {
        throw OVERFLOW;
    }
    else
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
}
void Array::ShowData()
{
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        cout<<ptr[i]<<" ";
    }
}
void Array::Insert(int index,int data)
{
    if(index<0 || index>lastIndex+1)
    {
        throw INVALID_INDEX;
    }
    if(lastIndex==capacity-1)
    {
        throw OVERFLOW;
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
void Array::Edit(int index,int data)
{
    if(index<0 || index>lastIndex+1)
    {
        throw INVALID_INDEX;
    }
    ptr[index]=data;
}
void Array::del(int index)
{
    if(index<0 || index>lastIndex+1)
    {
        throw INVALID_INDEX;
    }
    else
    {
        int i;
        for(i=index;i<=lastIndex;i++)
        {
            ptr[i]=ptr[i+1];
        }
        lastIndex--;
    }
}
bool Array::is_Full()
{
    return lastIndex==capacity-1;
}
int Array::get_Element(int index)
{
    if(index<0 || index>lastIndex)
    {
        throw INVALID_INDEX;
    }
    else
    {
        cout<<endl<<ptr[index]<<endl;
    }
}
int Array::count_Element()
{
    cout<<"\nTotal elements in the array="<<lastIndex+1<<endl;
}
Array::~Array()
{
    delete []ptr;
}
int Array::found(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        if(ptr[i]==data)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    Array arr(5);
    arr.Append(11);
    arr.Append(22);
    arr.Append(33);
    arr.Append(44);
    arr.Append(55);
    arr.get_Element(2);
    arr.count_Element();
    //arr.Insert(4,88);
    arr.Edit(2,55);
    //arr.del(2);
    if(arr.is_Full())
    {
        cout<<"True\n";
    }
    else
    {
        cout<<"False";
    }
    arr.ShowData();
    cout<<endl;
    return 0;
}