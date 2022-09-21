#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main() {
    int m;
    int n;
    cin >> m;
    cin >> n;
    int a[m][n];//to store numbers
    int b[m][n];//to store !use/use
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            b[i][j]=0;//unused
        }
    }

    int result[m*n];
    int k=0;

    if(m==1){
        for(int i=0;i<n-1;i++){
            cout << a[0][i];
            cout << " ";
        }
        cout << a[0][n-1];
        return 0;
    }
    if(n==1){
        for(int i=0;i<m-1;i++){
            cout << a[i][0];
            cout << " ";
        }
        cout << a[m-1][0];
        return 0;
    }
    for(int i=0;i<n;i++){
        result[k]=a[0][i];
        k=k+1;
        b[0][i]=1;
    }
    for(int i=1;i<m;i++){
        result[k]=a[i][n-1];
        k=k+1;
        b[i][n-1]=1;
    }
    for(int i=n-2;i>=0;i--){
        result[k]=a[m-1][i];
        k=k+1;
        b[m-1][i]=1;
    }
    for(int i=m-2;i>0;i--){
        result[k]=a[i][0];
        k=k+1;
        b[i][0]=1;
    }
    int cur_row=1;int cur_col=1;

    while(k!=m*n){
        if(b[cur_row][cur_col+1]==1){//cannot right
            if(b[cur_row+1][cur_col]==1){//cannot down
                if(b[cur_row][cur_col-1]==0){
                result[k]=a[cur_row][cur_col];
                k=k+1;
                b[cur_row][cur_col]=1;
                cur_col=cur_col-1;}
                else{
                    result[k]=a[cur_row][cur_col];
                    k=k+1;
                    b[cur_row][cur_col]=1;
                    cur_row=cur_row-1;
                }
            }else{
                result[k]=a[cur_row][cur_col];
                k=k+1;
                b[cur_row][cur_col]=1;
                cur_row=cur_row+1;
            }
        }else{//cannot lef
            if(b[cur_row-1][cur_col]==1){//cannot up
                result[k]=a[cur_row][cur_col];
                k=k+1;
                b[cur_row][cur_col]=1;
                cur_col=cur_col+1;
            }else{
                result[k]=a[cur_row][cur_col];
                k=k+1;
                b[cur_row][cur_col]=1;
                cur_row=cur_row-1;
            }
        }
    }
    for(int i=0;i<m*n-1;i++){
        cout << result[i];
        cout << " ";
    }
    cout << result[m*n-1];
    return 0;

}