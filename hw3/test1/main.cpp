#include <iostream>
#include <string>
using namespace std;

//链表长度大于等于1
struct Node{
int k;
Node *next;
};

int get_node_len(Node *p);
int main() {
    int in_num;
    Node *first=new Node;
    Node *current=first;

    while(){


    }
    int length= get_node_len(first);
    for(int i=length;i>=1;i--){
        current=first;
        for(int j=2;j<=i;j++){
            current=current->next;
        }
        cout << current->k;
        if(i!=1){
            cout << " ";
        }
    }
}
int get_node_len(Node *p){
    int result=1;
    while(p->next!= nullptr){
        p=p->next;
        result=result+1;
    }
    return result;
}