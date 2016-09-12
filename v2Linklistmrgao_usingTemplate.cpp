#include <iostream>

using namespace std;

template<typename T>
class linkedList {
    public:
    struct Node {
        T *data;
        Node *next;

        Node() {
            this->next = nullptr;
        }

        Node(T *d, Node *n = nullptr) {
            this->data = d;
            this->next = n;
        }
    };
private:
    Node *head;
 public:

    linkedList() {
        this->head = new Node();
    }

    void insert(T *data) {
        Node *end = head;
        while (end->next != nullptr) {
            end = end->next;
        }
        Node *newNode = new Node(data);
        end->next = newNode;
    }

    void deleteNode(T *data) {
        Node *preNode = head;
        while (preNode->next != nullptr) {
            if (*(preNode->next->data) == *data) {
                Node *tmpNode = preNode->next->next;
                delete preNode->next;
                preNode->next = tmpNode;
            }
        }
    }

    Node *search(T *data) {
        Node *node = head;
        while (node->next != nullptr) {
            if (*(node->next->data) == *data) {
                return node->next;
            }
        }
        return nullptr;
    }

    void printList()
    {
        /*
        Node *node = head;
        while(node->next!=NULL){
            cout<<*(node->next->data)<<" ";
            node=node->next;
        }
        cout<<endl;
        */
         for(Node *node = head;node->next!=NULL;node=node->next)
         {
              cout<<*(node->next->data)<<" ";
         }
         cout<<endl;
    }
};

int main(){
    linkedList<int> a;
    int number[] = {23,22};
    for(int i= 0; i<2;i++)
        a.insert(&number[i]);
    a.printList();

}
