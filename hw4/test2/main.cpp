#include <iostream>

class Content {
public:
    explicit Content(int id) : id(id) {
        std::cout << "create " << std::to_string(id) << std::endl;
    }

    ~Content() {
        std::cout << "destroy " << std::to_string(id) << std::endl;
    }

private:
    int id{-1};
    char data[1024]{};
};

class SharedContainer {
public:
    //构造函数
    explicit SharedContainer(int mem_id){
        Content* content=new Content(mem_id);
        this->_data=content;//定向地址
        this->ref_count=new int;//分配空间
        *(this->ref_count)=1;//赋值
        this->is_first_created=0;//已创建
    }
    //析构函数
    ~SharedContainer() {
        *(this->ref_count)-=1;//赋值
        if(!*(this->ref_count)){
            delete this->_data;
        }
    }
    //拷贝构造 注意可能有Content的析构
    SharedContainer(const SharedContainer &other){
        if(this->_data==other._data){//如果本来指向相同 啥都不用干
            return;
        }else if(is_first_created){//还没创建过呢
            this->_data=other._data;
            this->is_first_created=0;
            this->ref_count=other.ref_count;
            *(this->ref_count)=*(this->ref_count)+1;
        }else{//创建过 并且指向不同
            if(*(this->ref_count)==1){//被替换的只有一个指向
                delete this->_data;//析构
            }else{
                *(this->ref_count)-=1;
            }
            this->_data=other._data;
            this->ref_count=other.ref_count;
            *(this->ref_count)=*(this->ref_count)+1;
        }
    }
    //拷贝赋值
    SharedContainer& operator=(const SharedContainer &other){
        if(this==&other){ //一个东西
            return *this;
        }
        if(this->_data==other._data){//如果本来指向相同 啥都不用干
            return *this;
        }else if(is_first_created){//还没创建过呢
            this->_data=other._data;
            this->is_first_created=0;
            this->ref_count=other.ref_count;
            *(this->ref_count)=*(this->ref_count)+1;
        }else{//创建过 并且指向不同
            if(*(this->ref_count)==1){//被替换的只有一个指向
                delete this->_data;//析构
            }else{
                *(this->ref_count)-=1;
            }
            this->_data=other._data;
            this->ref_count=other.ref_count;
            *(this->ref_count)=*(this->ref_count)+1;
        }
        return *this;
    }
    //返回数字
    int get_count() const{
        return *ref_count;
    }

    SharedContainer(const SharedContainer &&) = delete;
    SharedContainer &operator=(const SharedContainer &&) = delete;

private:
    Content *_data{nullptr};
    int is_first_created=1;//ref_count表示这个SharedContainer未创建过
    int *ref_count;

};

void test1(){
    SharedContainer m1(1);//create 1
    SharedContainer m2 = m1;
    SharedContainer m3(m2);
    std::cout << m1.get_count() << std::endl;//3
    std::cout << m2.get_count() << std::endl;//3
    std::cout << m3.get_count() << std::endl;//3
}
//destroy 1
void test2(){
    SharedContainer m1(1);//create 1
    SharedContainer m2 = m1;
    m1 = m1;
    {
        SharedContainer m3 = m1;
        std::cout << m1.get_count() << std::endl;//3
    }
    std::cout << m1.get_count() << std::endl;//2
    std::cout << m2.get_count() << std::endl;//2
}
//destroy 1
void test3(){
    SharedContainer m1(1);//create 1
    SharedContainer m2(2);//create 2
    m1 = m2;//destroy 1
    std::cout << m1.get_count() << std::endl;//2
    std::cout << m2.get_count() << std::endl;//2
    {
        SharedContainer m3(3);//create 3
        m1 = m3;
        std::cout << m1.get_count() << std::endl;//3
        std::cout << m2.get_count() << std::endl;//3
        std::cout << m3.get_count() << std::endl;//3
    }
    std::cout << m1.get_count() << std::endl;//2
    std::cout << m2.get_count() << std::endl;//2

}
//destroy 2
//destroy 3
int main(){
    test1();
    test2();
    test3();
    return 0;
}