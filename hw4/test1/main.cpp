#include <iostream>

class MyContainer {
public:
    MyContainer(int size) : _size(size) {
        _size=size;//size->_size
        _data=new int[_size];//分配空间
        _count=1;//共创建了_count个实例
    }

    ~MyContainer() {
        delete _data;
        _count-=1;
    }

    MyContainer(const MyContainer &Other) {
        _size=Other._size;
        _data=new int[Other._size];
        _count=Other._count+1;
    }

    MyContainer &operator=(const MyContainer &Other) {
        if(this==&Other){
            return *this;
        }
        _size=Other._size;
        delete _data;
        _data=new int[Other._size];
        return *this;
    }

    int size() const {
        return _size;
    }

    int* data() const {
        return _data;
    }

    static int count() {
        return _count;
    }

    static int _count;

private:
    // C++11 引入的 initializer_list
    int *_data{nullptr};
    int _size{0};
};

int MyContainer::_count = 0;

void test1(){
    MyContainer m(5);
    std::cout << m.count() << std::endl;//1

    MyContainer m2(m);
    std::cout << m2.count() << std::endl;//2

    MyContainer m3 = m2;
    std::cout << m3.count() << std::endl;//3
}

void test2(){
    MyContainer m1(5);
    std::cout << m1.count() << std::endl;//1

    MyContainer m2 = m1;
    std::cout << m2.count() << std::endl;//2
    std::cout << (m2.data() == m1.data()) << std::endl;//0
}

void test3(){
    MyContainer m1(3);
    std::cout << m1.count() << std::endl;//1

    MyContainer m2 = m1;
    std::cout << m2.count() << std::endl;//2
    std::cout << (m2.data() == m1.data()) << std::endl;//0

    m1 = m2;
    std::cout << m1.count() << std::endl;//2 拷贝赋值函数错误
    std::cout << (m2.data() == m1.data()) << std::endl;//0

    m2 = m1;
    std::cout << m2.count() << std::endl;//2
    std::cout << (m2.data() == m1.data()) << std::endl;//0

    int * prev_ptr = m1.data();
    m1 = m1;
    std::cout << m1.count() << std::endl;//2
    std::cout << (m1.data() == prev_ptr) << std::endl;//1

}

void test4(){
    MyContainer m1(3);
    std::cout << m1.count() << std::endl;//1

    {
        MyContainer m2 = m1;
        std::cout << m2.count() << std::endl;//2
        std::cout << (m2.data() == m1.data()) << std::endl;//0

        m1 = m2;
        std::cout << m1.count() << std::endl;//2
        std::cout << (m2.data() == m1.data()) << std::endl;//0

        m2 = m1;
        std::cout << m2.count() << std::endl;//2
        std::cout << (m2.data() == m1.data()) << std::endl;//0

    }

    std::cout << m1.count() << std::endl;//1
}


int main(){
    test1();
    test2();
    test3();
    test4();
    return 0;
}