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
/* which is on2
    void DeleteValue(int value)
    {
        for(int i= 0;i<length;i++)
        {
            if(data[i]==value)
            {
                DeleteList(i+1);
                --i;//be careful otherwise a number may be skipped
            }
        }
    }
*/
/*
    void DeleteValue(int value)
    {
        int i=0;
        do
        {
            if(data[i]==value)
            {
                int pos = i;
                for(int j= pos;j<length;j++)
                    data[j]=data[j+1];
                length--;
            }

        }
        while(i++<length);

    }
*/

void DeleteValue(int value){
    int deleteCount = 0;

    for(int i=0;i<length-deleteCount;++i){
        while(data[i+deleteCount] == value){
            ++deleteCount;
        }
        if(deleteCount != 0){
            data[i] = data[i+deleteCount];
        }
    }
    length -= deleteCount;
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
    int value;
    SeqList listmm;
    listmm.InitList();
    listmm.InsertList(a,10);
    listmm.PrintList();
    listmm.InsertList(a,10);
    listmm.PrintList();
    listmm.DeleteList(3);
    cout<<"after delete the value of position 3\n";
    listmm.PrintList();
    cout<<"input the value you want to delete\npress 0 to quit\n";
    while( cin>>value)
   {
       if(value==0)
            break;
        listmm.DeleteValue(value);
        listmm.PrintList();
        cout<<"input the value you want to delete\n";

   }




}
