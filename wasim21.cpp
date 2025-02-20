#include<iostream>
using namespace std;
#define INVALIDINDEX 2;
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
        int i=-1;
    public:
        DynArray();
        void Append(int);
        void showData();
        bool is_Empty();
        void Insert(int,int);
        void Edit(int,int);
        void del(int);
        bool is_Full();
        int get(int);
        int count();
        ~DynArray();
        int found(int);
};
DynArray::DynArray()
{
    i++;
    capacity=i;
    lastIndex=-1;
    ptr=new int[capacity];
}
bool DynArray::is_Empty()
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
void DynArray::Append(int data)
{
    ptr[i]=data;
    lastIndex++;
    i++;
}
void DynArray::Insert(int index,int data)
{
    if(index<0 || index>lastIndex+1)
    {
        throw INVALIDINDEX;
    }
    int i;
    lastIndex++;
    for(i=lastIndex;i>=index;i--)
    {
        ptr[i+1]=ptr[i];
    }
    ptr[index]=data;
}
void DynArray::Edit(int index,int data)
{
    if(index<0 || index>lastIndex+1)
    {
        throw INVALIDINDEX;
    }
    ptr[index]=data;
}
void DynArray::del(int index)
{
    if(index<0 || index>lastIndex+1)
    {
        throw INVALIDINDEX;
    }
    int i;
    for(i=index;i<lastIndex+1;i++)
    {
        ptr[i]=ptr[i+1];
    }
    lastIndex--;
}
bool DynArray::is_Full()
{
    return lastIndex==-1;
}
int DynArray::get(int index)
{
    if(index<0 || index>lastIndex+1)
    {
        throw INVALIDINDEX;
    }
    cout<<endl<<ptr[index]<<endl;
}
int DynArray::count()
{
    cout<<"Total Element in the Dynamic Array="<<lastIndex+1<<endl;
}
DynArray::~DynArray()
{
    delete []ptr;
}
int DynArray::found(int data)
{
    int i;
    for(i=0;i<lastIndex+1;i++)
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
void DynArray::showData()
{
    int i;
    for(i=0;i<=lastIndex;i++)
    {
        cout<<ptr[i]<<" ";
    }
}
int main()
{
    DynArray arr;
    arr.Append(22);
    arr.Append(55);
    arr.Append(66);
    arr.Insert(2,99);
    arr.Insert(0,87);
    arr.Insert(5,54);
    arr.Edit(2,33);
    arr.del(2);
    arr.get(1);
    arr.count();
    arr.showData();
    arr.found(77);
    arr.is_Empty();
    cout<<endl;
    return 0;
}