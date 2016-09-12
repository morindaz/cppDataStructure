
/* question:
1. ptr is a pointer ,so what  the ptr->length is ?
2. in line 79 the for loop, how does the last data[i] exist?
3. in line 144, why the value of number can be fetched?
*/
#include<iostream>
using namespace std;
typedef int ElemType;
#define MAXSIZE 20

typedef struct
{
    ElemType data[MAXSIZE];//define an array with maxsize 20
    int length;
}SqList;

//initialize sequential list
bool InitList(SqList *ptr)
{
    for(int i = 0; i<MAXSIZE;i++)
    {
        ptr->data[i] = 0; //initial the data to 0
    }
    ptr->length = 0; //if there's no new number substitute 0
    return true;//then the length is still 0

}


bool ListEmpty(SqList Sq)
{
    if(Sq.length == 0)
        return true;
    else
        return false;
}


bool ClearList(SqList *ptr)
{
    for(int i = 0;i<ptr->length;i++)//can ptr-length mean the length of list?
    {
        ptr->data[i] = 0;//make the data of node to 0
    }
    ptr->length = 0;//??? make the whole length to 0
    return true;//if the process finishes, then return the bool value true
}

bool GetElem(SqList Sq, int pos, ElemType *ptr)//the parameter needs to be passed
{        //is the SqList needs to be searched,the position in the SqList and the pointer ptr
    if(Sq.length ==0||pos<1||pos>Sq.length)
        return false;
    *ptr = Sq.data[pos-1];
    return true;
}

int Locate(SqList Sq, ElemType Elem) //which needs to find the position of the related Elem value
{
    for(int i= 0; i<Sq.length;i++)//rotate from the first place to the end of the List
    {
        if(Sq.data[i]==Elem)//if there exists the data node equals to Elem
        {
            return i+1;//the array counts from 0, thus the position is the number+1
        }
    }
    return 0;
}

//insert an element ELEM before the position
bool ListInsert(SqList *ptr, int pos, ElemType Elem)//the parameters needs to be passed
{  //is the pointer ptr that points to the SqList, the position where the element needs to be inserted
    if(ptr->length ==MAXSIZE)
        return false;// if the length is up to the maximum size,then no data can be inserted
    if(pos<1||pos>ptr->length+1)
        return false;
    if(pos<=ptr->length)//the case that data can be inserted
    {
        for(int i = ptr->length-1;i>=pos-1;i--)
        {
            ptr->data[i+1] = ptr->data[i];

        }
    }

    ptr->data[pos-1] = Elem;
    ptr->length++;
    return true;
}

int ListLength(SqList Sq)
{
    return Sq.length;
}

void UnionList(SqList *pa,SqList*pb) //union two SqList
{
    int lena = pa->length;
    int lenb = pb->length;
    int item;
    for(int i = 0; i<lenb;i++)
    {
        if(GetElem(*pb,i+1,&item))//bool GetElem(SqList Sq, int pos, ElemType *ptr)//the parameter needs to be passe
        {
            if(Locate(*pa,item)==0) //int Locate(SqList Sq, ElemType Elem)
            {
                ListInsert(pa,++lena,item);//bool ListInsert(SqList *ptr, int pos, ElemType Elem)
            }
        }
    }
}


bool ListDelete(SqList *ps,int pos, ElemType *pe)
{
    if(pos<1||pos>ps->length)
        return false;
    *pe = ps->data[pos-1];
    for(int i = pos;i<ps->length;i++)
    {
        ps->data[i-1] = ps->data[i];
    }
    ps->length--;
    return true;
}

int main()
{
    SqList Sq; // a case of the struct SqList
    InitList(&Sq);//bool InitList(SqList *ptr) the parameter needs to be passed is
    for(int i =1;i<5;i++)
        ListInsert(&Sq,i,i);//bool ListInsert(SqList *ptr, int pos, ElemType Elem)//the parameters needs to be passed
    if(!ListEmpty(Sq))//bool ListEmpty(SqList Sq)
    {
        cout<<"Sq: "<<endl;
        for(int i = 0;i<ListLength(Sq);i++)  //int ListLength(SqList Sq)
            cout<<Sq.data[i]<<' ';
    }
    cout<<endl;

    int pos = Locate(Sq,2);
    if(pos!=0)
    {
        int result; //why result can denote the value 2?
        ListDelete(&Sq,pos,&result);
        cout<<"delete: "<<result<<endl;
        ListDelete(&Sq,pos,&result);
    }

    if(!ListEmpty(Sq))//bool ListEmpty(SqList Sq)
    {
        cout<<"Sq: "<<endl;
        for(int i = 0;i<ListLength(Sq);i++)  //int ListLength(SqList Sq)
            cout<<Sq.data[i]<<' ';
    }
    cout<<endl;

    SqList Sq2;
    InitList(&Sq2);
    for(int i = 1;i<4;i++)
        ListInsert(&Sq2,4,7);
    ListInsert(&Sq2,4,7);
    if(!ListEmpty(Sq2))
    {
        cout<<"Sq2:"<<endl;
    for(int i = 0;i<ListLength(Sq2);i++)
        cout<<Sq2.data[i]<<' ';
    }
    cout<<endl;
    UnionList(&Sq,&Sq2);
    if(!ListEmpty(Sq))
    {
        cout<<"Sq:"<<endl;
        for(int i = 0;i<ListLength(Sq);i++)
            cout<<Sq.data[i]<<' ';
    }
    cout<<endl;
}
