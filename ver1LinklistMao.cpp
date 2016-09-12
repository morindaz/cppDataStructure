/*this code finishes establishing a list
and the functions are insert a node \delete a node
as well as output the current
the knowledge as following are used:
struct
class
pointer
dynamic memory allocation

*/
#include<iostream>
using namespace std;
 struct Node{
        int data;
        Node *next;
};

class list{
    Node *head;
public:
    list(){head=NULL;}
    void insertlist(int aData, int bData);
    void deletelist(int aData);
    void outputlist();
    Node *gethead();
};

void list::insertlist(int aData, int bData)
{
    Node *p,*q,*s; //p is head, s is the node needs to be inserted
    s = new Node;//Not so clear
    s->data = bData;
    p = head;
    if(NULL == head){//if there's no exist node, then s(the node)
        head = s;//needs to be inserted is the first node(head)
        s->next=NULL;//and the following nodes are NULL
    }
    else
    {
        if(p->data==aData)//if a is the head
        {
            s->next = p; //insert s before head p
            head = s; //then s is the head
        }
        else
        {
          while(p->data!=aData&&p->next!=NULL)//if aData does not equal to head
          {
              q = p;//q denotes the node before p
              p = p->next; //search the node p equal to aData
          }
          if(p->data==aData)
          {
              q->next = s;
              s->next = p;
          }
          else// there is no nodes equal to aData
          {
              p->next = s;
             //insert the node after p
          }
        }
    }
}

void list::deletelist(int aData)
{
    Node *p,*q;//p denotes the current node, and q is the node before p
    p = head;//circulate from the first head to the node equals aData
    if(NULL==p)
    {
        return;
    }
    if(p->data==aData)//aData is the first head node
    {
        head = p->next;//delete the p node
        delete p;
    }
    else
    {
        while(p->data!=aData&&p->next!=NULL)
        {
            q = p;//q denotes the node before p
            p = p->next;
        }
        if(p->data==aData)//if there exists a code equals to aData
        {
            q->next=p->next;//then delete the current p node
            delete p;
        }


    }
}


void list::outputlist()
{
    Node *current = head;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;

}

int main(){
    list A,B;
    int Data[]={25,41,16,98,5,67,9,55,1,121};
    A.insertlist(0,Data[0]);
    for(int i=1;i<10;i++)
    {
        A.insertlist(0,Data[i]);
    }
    cout<<"\nÁ´±íA: ";
    A.outputlist();
    A.deletelist(55);
    A.deletelist(25);
     cout<<"\nÁ´±íA: ";
    A.outputlist();
     A.deletelist(41);
     cout<<"\nÁ´±íA: ";
    A.outputlist();
    return 0;
}
