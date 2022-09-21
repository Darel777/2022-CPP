#include <iostream>
#include <string>
#include <math.h>
using namespace std;
struct Node{int key;string value;Node* next;};
struct Entry{int hashcode;Node* next;};
struct HashDict{int size;Entry* array;};//只有一开始或是再散列时定义好，其它的size都是没有意义的
//HashDict节点个数超过现有数组长度时再散列
//向某一个桶中的链表增加元素后，该链表长度超过4，再散列
int cal_pos(int key,int length);
int to_int(string a);
void add(HashDict* hashDict,int position,int key,string value);
void del(HashDict* hashDict,int position,int key);
void search(HashDict* hashDict,int position);
bool if_rehash(HashDict* hashDict,int length_hash);//判断是否需要再散列
int sums(HashDict* hashDict,int length);
void re_hash(HashDict* hashDict,int length_hash,int items);//再散列

int main() {
    //original_length 原哈希表长度
    int original_length;cin >> original_length;
    //创建hashDict
    HashDict* hashDict = new HashDict();
    hashDict->size = original_length;
    hashDict->array = new Entry[original_length];
    //初始化
    for(int i=0;i<original_length;i++){hashDict->array[i].hashcode=i;hashDict->array[i].next=nullptr;}
    //instructions 指令数
    int instructions;cin >> instructions;cin.get();

    //循环指令
    for(int i=0;i<instructions;i++){
        string instruction;
        cin >> instruction;
        if(instruction.substr(0,3)=="add"){//添加
            int key;string value;
            cin >> key;
            cin >> value;
            int position= cal_pos(key,original_length);
            add(hashDict,position,key,value);
        }
        else if(instruction.substr(0,3)=="del"){//删除
            int key;
            cin >> key;
            int position= cal_pos(key,original_length);
            del(hashDict,position,key);
        }
        else if(instruction.substr(0,3)=="sea"){//查找
            int position;
            cin >>position;
            search(hashDict,position);
        }
        case4:
        if(if_rehash(hashDict,original_length)){
            int items= sums(hashDict,original_length);
            original_length=original_length*2+1;
            re_hash(hashDict,original_length,items);
        }
        if(if_rehash(hashDict,original_length)){
            goto case4;
        }
    }

}
int cal_pos(int key,int length){
    long long int hash=0;hash+=3* pow(key,3);hash+=5* pow(key,2);hash+=7*key+11;
    hash=abs(hash);
    hash=hash%length;
    return hash;
}//length为哈希表长度
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
}//string转int
void add(HashDict* hashDict,int position,int key,string value){
    Node* node=new Node();
    node->key=key;
    node->value=value;
    node->next= nullptr;
    if(hashDict->array[position].next== nullptr){
        hashDict->array[position].next=node;return;//空的 直接加
    }else{
        Node* iterator;
        iterator=hashDict->array[position].next;
        if(key<iterator->key){
           node->next= hashDict->array[position].next;
            hashDict->array[position].next=node;//填到紧挨着的位置
        }else{
            case1:
            if(iterator->next== nullptr){
                iterator->next=node;return;
            }else if(key>iterator->key&&key<iterator->next->key){
                node->next=iterator->next;
                iterator->next=node;return;
            }else{
                iterator=iterator->next;
                goto case1;
            }
        }
    }
}//add
void del(HashDict* hashDict,int position,int key){
    Node* iterator;
    iterator=hashDict->array[position].next;
    if(key==iterator->key){
        hashDict->array[position].next=hashDict->array[position].next->next;//第一个就是
    }else{
        case2:
        if(key==iterator->next->key){
            iterator->next=iterator->next->next;
        }else{
            iterator=iterator->next;
            goto case2;
        }
    }
}
void search(HashDict* hashDict,int position){
    if(hashDict->array[position].next== nullptr){
        cout << "null" << endl;return;
    }else{
        Node* iterator=hashDict->array[position].next;
        case3:
        cout << iterator->key << ":" << iterator->value;
        if(iterator->next== nullptr){
            cout << endl;
            return;
        }else{
            iterator=iterator->next;
            cout << "->";
            goto case3;
        }
    }
}
bool if_rehash(HashDict* hashDict,int length){
    int total=0;
    for(int i=0;i<length;i++){
        int part_total=0;
        Node* iterator=hashDict->array[i].next;
        while(iterator!= nullptr){
            total+=1;
            part_total+=1;
            iterator=iterator->next;
        }
        if(part_total>4){
            return true;
        }
    }
    if(total>length){
        return true;
    }else{
        return false;
    }
}
int sums(HashDict* hashDict,int length){
    int total=0;
    for(int i=0;i<length;i++){
        Node* iterator=hashDict->array[i].next;
        while(iterator!= nullptr){
            total+=1;
            iterator=iterator->next;
        }
    }
    return total;
}
void re_hash(HashDict* hashDict,int length_hash,int items){
    int original_length=(length_hash-1)/2;//length_hash->new  original_length->old
    int keys[items];
    string values[items];
    int z=0;
    for(int i=0;i<original_length;i++){
        Node* iterator=hashDict->array[i].next;
        while(iterator!= nullptr){
            keys[z]=iterator->key;
            values[z]=iterator->value;
            z=z+1;
            iterator=iterator->next;
        }
    }
    hashDict->array=new Entry[length_hash];
    hashDict->size=length_hash;
    for(int i=0;i<length_hash;i++){
        hashDict->array[i].next= nullptr;
    }
    for(int i=0;i<items;i++){
        int position= cal_pos(keys[i],length_hash);
        add(hashDict,position,keys[i],values[i]);
    }
}

