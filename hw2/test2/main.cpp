#include <iostream>
using namespace std;
int main() {
    int size,degree;
    cin >> size;
    cin >> degree;
    int mode=(degree%360);//0 90 180 270
    int a[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin >> a[i][j];
        }
    }
    if(mode==0){//ridiculous no tests here!
        for(int i=0;i<size;i++){
            for(int j=0;j<size-1;j++){
                cout << a[i][j];
                cout << " ";
            }

            if(i!=size-1){
            cout << "\n";
            }
        }
    }else if(mode==90){
        for(int j=0;j<=size-1;j++){
            for(int i=size-1;i>0;i--){
                cout << a[i][j];
                cout << " ";
            }
            cout << a[0][j];
            if(j!=size-1){
                cout << "\n";
            }
        }
    }else if(mode==180){
        for(int i=size-1;i>=0;i--){
            for(int j=size-1;j>=0;j--){
                cout << a[i][j];
                cout << " ";
            }

            if(i!=0){
                cout << "\n";
            }
        }
    }else if(mode=270){
        for(int j=size-1;j>=0;j--){
            for(int i=0;i<size;i++){
                cout << a[i][j];
                cout << " ";
            }
            if(j!=0){
                cout << "\n";
            }
        }
    }
}
