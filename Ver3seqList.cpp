#include<iostream>
using namespace std;
#define MAX 20

class SeqList
{
    public:
        int data[MAX];
        int length;

    void InitList()
    {
       for(int i = 0; i<MAX;i++)
       {
        data[i] =0;
       }
       length = 0;
    }

    bool InsertList(int a[],int len)
    {
        length = length+len;

        if(length>MAX)
            return false;
        else
        {
            for(int i=0;i<len;i++)
            {
                //cout<<a[19]<<endl;
                data[length-len+i] = a[i];
            }

        }
        return true;

    }

    void DeleteList(int pos)
    {
        for(int i = pos;i<length;i++)
        {
            data[i-1]=data[i];
        }
        length--;
    }

    void PrintList()
    {
        for(int i =0;i<length;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    int a[10] = {10,56,32,23,56,3,2,3,2,1};
    SeqList listmm;
    listmm.InitList();
    listmm.InsertList(a,10);
    listmm.PrintList();
    listmm.InsertList(a,10);
    listmm.PrintList();
    listmm.DeleteList(3);
    listmm.PrintList();

}
