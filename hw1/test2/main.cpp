#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++){
        cin >>a[i];
    }
    long temp=1;
    for(int i=0;i<N;i++){
        temp*=a[i];
        if(temp<numeric_limits<int>::min()||temp>numeric_limits<int>::max()){
            cout << -1;
            return 0;
        }
        cout <<temp;
    }
    return 0;
}
