#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <typeinfo>
using namespace std;
typedef struct node{
    int key;
    struct node *lChild, *rChild;
}Node, *BST;//what does *BST and Node mean here?

bool BSTInsert(Node *&p, int element){ //What does Node *&p mean here?
    if(NULL==p){
        p = new Node;
        p->key = element;
        p->lChild = p->rChild  = NULL;
        return true;
    }
    if(element == p->key)
        return false;
    if(element< p->key)
        return BSTInsert(p->lChild,element);
    return BSTInsert(p->rChild,element);
}
/*
void createBST(Node *&T, int a[], int n){
    T = NULL;
    int i;
    for(i = 0;i < n;i++){
        BSTInsert(T,a[i]);
    }
}
*/
void inOrderTraverse(BST T){
    if(T){
        inOrderTraverse(T->lChild);
        cout<<T->key<<" ";
        inOrderTraverse(T->rChild);
    }
}



void Tree_Delete(BST T, int keydel)      //ɾ��ָ���Ľڵ�
{
    BST p = T,q,f,s;//?????????????
    while(p)                   //��Ѱ�ҵ�Ҫɾ���Ľڵ�
    {
         if(keydel == p->key)
         {
             break;
         }
         f = p;
         p=(keydel<p->key)?p->lChild:p->rChild;
    }
   if(!p)
   {
         cout<<"��������û�нڵ�,����ɾ��!"<<"\n";
   }
   else if(!p->lChild && !p->rChild)
   {
          if(p == T) T=NULL;
            if(p == f->lChild)
            f->lChild = NULL;
          else
            f->rChild = NULL;
          delete p;
          p = NULL;
   }
   else if(!p->lChild && p->rChild)
   {
       if(f->lChild == p)
           f->lChild = p->rChild;
       else
           f->rChild = p->rChild;
       delete p;
       p = NULL;
   }
   else if(!p->rChild && p->lChild)
   {
        if (f->lChild == p)
          f->lChild = p->lChild;
        else
          f->rChild = p->lChild;
        delete p;
        p = NULL;
   }
   else  //��ڵ�����Һ���
   {
       q = p;
       s = p->lChild;
       while(s->rChild)
       {
           q = s;
           s = s->rChild;
       }
       p->key = s->key;
       if(q!=p) q->rChild=s->lChild;
       else q->lChild = s->lChild;
       delete s;
       s = NULL;
   }
}



BST Tree_Insert(BST T, int keyins) //insert the key
{
    BST p = T;
    BST f,s;
    while(p != NULL)
    {
        f= p;
        if(keyins == p->key)
        {
               cout<<"Ҫ����Ľڵ��Ѵ��ڣ������ٲ��룡"<<endl;
               return T;
        }
        p = (keyins > p->key)? p->rChild:p->lChild;
    }
    s = new Node;
    s -> key = keyins;
    s -> lChild = NULL;
    s -> rChild = NULL;
    if(T == NULL) return s;
    if(keyins < f->key)
    f -> lChild = s;
    else
    f -> rChild = s;
    return T;
}


int main(){
    ifstream myfile("in.txt");
    int Content;
    BST T;
    int n = 1;
    int key;
    while(myfile>>Content)// int n = sizeof(a)/sizeof (int);
   {
       //createBST(T,Content,n);
        cout<<Content;
   }
    inOrderTraverse(T);
    cout<<endl;
    cout<<"������Ҫɾ���Ľڵ�Ĺؼ���:"<<"\n";
    cin>>key;
    Tree_Delete(T, key);
    inOrderTraverse(T);
    cout<<"\n";
    cout<<"������Ҫ����Ľڵ�Ĺؼ���:"<<"\n";
    cin>>key;
    T = Tree_Insert(T, key);
    cout<<"\n";
    inOrderTraverse(T);
    return 0;
}

