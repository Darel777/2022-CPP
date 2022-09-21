#include <iostream>
using namespace std;

class MyBitVector {
private:
public:
    explicit MyBitVector(int size) {
        this->size=size;
        for(int i=0;i<this->size;i++){
            data[i]='0';
        }
    }

    explicit MyBitVector(const string &s) {
        this->size=s.length();
        for(int i=0;i<this->size;i++){
            data[i]=s[i];
        }
    }

    void set(int index) {
        this->data[index]='1';
    }

    void clear(int index) {
        this->data[index]='0';
    }

    bool get(int index) {
        if(this->data[index]=='0'){
            return false;
        }else{
            return true;
        }
    }

    void print() {
        for(int i=0;i<this->size;i++){
            cout << this->data[i];

        }
        cout << endl;
    }

    // TODO: operator overloads to generate new bitvectors from existing ones
    MyBitVector operator&(MyBitVector &other) {
        MyBitVector myBitVector(this->size);
        for(int i=0;i<this->size;i++){
            if(this->data[i]==other.data[i]&&other.data[i]=='1'){
                myBitVector.data[i]='1';
            }else{
                myBitVector.data[i]='0';
            }
        }
        return myBitVector;
    }

    MyBitVector operator|(MyBitVector &other) {
        MyBitVector myBitVector(this->size);
        for(int i=0;i<this->size;i++){
            if(this->data[i]==other.data[i]&&other.data[i]=='0'){
                myBitVector.data[i]='0';
            }else{
                myBitVector.data[i]='1';
            }
        }
        return myBitVector;
    }

    MyBitVector operator^(MyBitVector &other) {
        MyBitVector myBitVector(this->size);
        for(int i=0;i<this->size;i++){
            if(this->data[i]!=other.data[i]){
                myBitVector.data[i]='1';
            }else{
                myBitVector.data[i]='0';
            }
        }
        return myBitVector;
    }

    MyBitVector operator~() {

        for(int i=0;i<this->size;i++){
            if(this->data[i]=='0'){
                this->data[i]='1';
            }else{
                this->data[i]='0';
            }
        }
        MyBitVector myBitVector=*this;
        for(int i=0;i<this->size;i++){
            if(this->data[i]=='0'){
                this->data[i]='1';
            }else{
                this->data[i]='0';
            }
        }
        return myBitVector;
    }

    MyBitVector &operator&=(MyBitVector &other) {
        for(int i=0;i<this->size;i++){
            if(this->data[i]==other.data[i]&&other.data[i]=='1'){
                this->data[i]='1';
            }else{
                this->data[i]='0';
            }
        }
        return *this;
    }

    MyBitVector &operator|=(MyBitVector &other) {
        for(int i=0;i<this->size;i++){
            if(this->data[i]==other.data[i]&&other.data[i]=='0'){
                this->data[i]='0';
            }else{
                this->data[i]='1';
            }
        }
        return *this;
    }

    MyBitVector &operator^=(MyBitVector &other) {
        for(int i=0;i<this->size;i++){
            if(this->data[i]!=other.data[i]){
                this->data[i]='1';
            }else{
                this->data[i]='0';
            }
        }
        return *this;
    }
int size=-1;
char data[1000]={'0'};
};

void test1() {
    MyBitVector bv1("01010100");
    MyBitVector bv2("11101111");
    MyBitVector bv3 = bv1 & bv2;
    bv1 &= bv2;
    bv1.print();
    bv2.print();
    bv3.print();
}

void test2() {
    MyBitVector bv1("00001000");
    MyBitVector bv2("11010011");
    MyBitVector bv3 = bv1 | bv2;
    bv1 |= bv2;
    bv1.print();
    bv2.print();
    bv3.print();
}

void test3() {
    MyBitVector bv1("00010010");
    MyBitVector bv2("10111001");
    MyBitVector bv3 = bv1 ^ bv2;
    bv1 ^= bv2;
    bv1.print();
    bv2.print();
    bv3.print();
}

void test4() {
    MyBitVector bv1("00100100");
    MyBitVector bv2 = ~bv1;
    bv1 = ~bv1;
    bv1.print();
    bv2.print();
}

void test5() {
    MyBitVector bv1("00000001");
    bv1.set(2);
    bv1.print();
}

#define TEST(x) std::cout << "test" << #x << "\n"; test##x();

int main() {
    TEST(1);
    TEST(2);
    TEST(3);
    TEST(4);
    TEST(5);
    return 0;
}