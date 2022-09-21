#include <cctype>
#include <cstring>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
using namespace std;
template <typename T>
class Rational {
public:
    Rational(const T &n, const T &d){
        if(d==0){
            throw std::logic_error("denominator must be != 0");
        }else{
            this->fenzi=n;
            this->fenmu=d;
        }
    };
    Rational(const Rational<T> &rhs){
        Rational(rhs.fenzi,rhs.fenmu);
    }
    T numerator() const{
        return fenzi;
    }
    T denominator() const{
        return fenmu;
    }

    Rational<T> operator+(const Rational<T> &rhs) const{
        int fenzi1=this->fenzi;
        int fenmu1=this->fenmu;
        int fenzi2=rhs.fenzi;
        int fenmu2=rhs.fenmu;
        int pub_deno=fenmu1*fenmu2;
        return Rational(fenzi1*(pub_deno/fenmu1)+fenzi2*(pub_deno/fenmu2),pub_deno);
    }
    Rational<T> operator-(const Rational<T> &rhs) const{
        int fenzi1=this->fenzi;
        int fenmu1=this->fenmu;
        int fenzi2=rhs.fenzi;
        int fenmu2=rhs.fenmu;
        int pub_deno=fenmu1*fenmu2;
        return Rational(fenzi1*(pub_deno/fenmu1)-fenzi2*(pub_deno/fenmu2),pub_deno);
    }
    Rational<T> operator*(const Rational<T> &rhs) const{
        return Rational(this->fenzi*rhs.fenzi,this->fenmu*rhs.fenmu);
    }
    Rational<T> operator/(const Rational<T> &rhs) const{
        return Rational(this->fenzi*rhs.fenmu,this->fenmu*rhs.fenzi);
    }

    Rational<T> &operator=(const Rational<T> &rhs){
        this->fenzi=rhs.fenzi;
        this->fenmu=rhs.fenmu;
    }

    friend std::ostream &operator<<(std::ostream &out, const Rational<T> &r){
        int a=r.fenzi/ gcd(r.fenzi,r.fenmu);
        int b=r.fenmu/ gcd(r.fenzi,r.fenmu);
        if(b==1){
            cout << a;
        }else{
            cout << a << "/" << b;
        }
    }

    static int gcd(int m, int n) {
        if(n==0){
            return m;
        }else{
            return gcd(n,m%n);
        }
    }
    int fenzi=1;
    int fenmu=1;
};


Rational<int> operator""_r(const char *str, size_t len){
    int k=-1;
    for(int i=0;i<len;i++){
        if (str[i]=='/'){
            k=i;
            break;
        }
    }
    string result1;
    string result2;
    for(int j=0;j<=k-1;j++){
        result1+=str[j];
    }
    for(int j=k+1;j<len;j++){
        result2+=str[j];
    }
     int i= atoi(result1.c_str());
     int j= atoi(result2.c_str());
     return Rational<int>(i,j);

}

void test_1() {
    Rational<int> r(3, 4);
    std::cout << r << std::endl;
}

void test_2() {
    bool exception_thrown = false;
    bool expected_message = false;
    try {
        Rational<int> r = Rational<int>(1, 0);
    } catch (std::logic_error &exn) {
        exception_thrown = true;
        if (!strncmp(exn.what(), "denominator must be != 0", 24)) {
            expected_message = true;
        }
    } catch (...) {
    }
    if (exception_thrown) {
        std::cout << "std::logic_error thrown!" << std::endl;
        if (expected_message) {
            std::cout << "the message is as expected." << std::endl;
        }
    } else {
        std::cout << "Oops!" << std::endl;
    }
}

void test_3() {
    Rational<int> r(3, 4);
    std::cout << r.numerator() << ' ' << r.denominator() << std::endl;
}

void test_4() {
    Rational<int> lhs(1, 6), rhs(1, 3);
    std::cout << (lhs + rhs) << std::endl;
}

void test_5() {
    Rational<int> lhs(1, 2), rhs(1, 6);
    std::cout << (lhs - rhs) << std::endl;
}

void test_6() {
    Rational<int> lhs(2, 4), rhs(4, 6);
    std::cout << (lhs * rhs) << std::endl;
}

void test_7() {
    Rational<int> lhs(2, 4), rhs(4, 6);
    std::cout << (lhs / rhs) << std::endl;
}

void test_8() {
    Rational<int> r(3, 4);
    std::cout << r << std::endl;
    Rational<int> rhs(101, 203);
    r = rhs;
    std::cout << r << ' ' << rhs << std::endl;
}

void test_9() {
    auto r = "3/4"_r;
    std::cout << r << std::endl;
}

void test_10() { std::cout << Rational<int>(4, 2) << std::endl; }

void test_11() {
    std::cout << (Rational<int>(1, 2) - Rational<int>(2, 4)) << std::endl;
}

void test_12() { std::cout << Rational<int>(3, 6) << std::endl; }

int main() {
    std::unordered_map<std::string, std::function<void()>> test_cases_by_name = {
            {"test_1", test_1},   {"test_2", test_2},   {"test_3", test_3},
            {"test_4", test_4},   {"test_5", test_5},   {"test_6", test_6},
            {"test_7", test_7},   {"test_8", test_8},   {"test_9", test_9},
            {"test_10", test_10}, {"test_11", test_11}, {"test_12", test_12},
    };
    std::string tname;
    std::cin >> tname;
    auto it = test_cases_by_name.find(tname);
    if (it == test_cases_by_name.end()) {
        std::cout << "输入只能是 test_<N>，其中 <N> 可取整数 1 到 12." << std::endl;
        return 1;
    }
    (it->second)();
}