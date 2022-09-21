#include <iostream>
#include <string>
using namespace std;
struct Node{Node* next;Node* prev;int val;
};
struct Deque{int size;Node* front;Node* rear;
};
void push_front (Deque* self, int value);
void push_back (Deque* self, int value);
void pop_front (Deque* self);
void pop_back (Deque* self);
int to_int(string a);
int main() {
    Deque* deque;deque=new Deque();deque->size=0;deque->front=new Node();deque->rear=new Node();
    deque->front->next=deque->rear;deque->rear->prev=deque->front;
    deque->front->prev=nullptr;deque->rear->next=nullptr;
    int instructions;cin >> instructions;cin.get();string instruction;

    for(int i=0;i<instructions;i++){
        getline(cin,instruction);
        if(instruction.substr(0,5)=="pushF"){
            int spa=instruction.find(" ");
            int num= to_int(instruction.substr(spa+1));
            push_front(deque,num);
        }else if(instruction.substr(0,5)=="pushB"){
            int spa=instruction.find(" ");
            int num= to_int(instruction.substr(spa+1));
            push_back(deque,num);
        }else if(instruction.substr(0,5)=="popFr"){
            pop_front(deque);
        }else if(instruction.substr(0,5)=="popBa"){
            pop_back(deque);
        }else if(instruction.substr(0,5)=="getSi"){
            cout << deque->size << endl;
        }
//        cout << "completed" << endl;
    }
    return 0;
}
void push_front (Deque* self, int value){
    Node* node=new Node();node->val=value;
    node->next=self->front->next;
    self->front->next->prev=node;
    self->front->next=node;
    node->prev=self->front;
    self->size++;
}
void push_back (Deque* self, int value){
    Node* node=new Node();node->val=value;
    node->prev=self->rear->prev;
    self->rear->prev->next=node;
    self->rear->prev=node;
    node->next=self->rear;
    self->size++;
}
void pop_front (Deque* self){
    if(self->size==0){
        cout << -1 << endl;
        return;
    }
    cout<<self->front->next->val<<endl;
    self->front->next=self->front->next->next;
    self->front->next->prev=self->front;
    self->size--;
}
void pop_back (Deque* self){
    if(self->size==0){
        cout << -1 << endl;
        return;
    }
    cout<<self->rear->prev->val<<endl;
    self->rear->prev=self->rear->prev->prev;
    self->rear->prev->next=self->rear;
    self->size--;
}
int to_int(string a){
    int result=0;
    if(a[0]=='-'){
        for(int i=1;a[i]!='\0';i++){
            result*=10;
            result+=(a[i]-48);
        }
        result=-result;
    }else{
        for(int i=0;a[i]!='\0';i++){
            result*=10;
            result+=(a[i]-48);
        }
    }
    return result;
}