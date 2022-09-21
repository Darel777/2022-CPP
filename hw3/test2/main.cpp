#include <iostream>
#include <cstddef>
#include <algorithm>
#include <iterator>

using namespace std;
int** matrix_multi(int **a,int **b,int row1,int row2,int col1,int col2);
int main() {
    int times;
    cin >> times;
    int in_num;
    int** p;

    int last_row,last_col;
    int cur_row1,cur_col1;
    int cur_row2,cur_col2;

    for(int i=2;i<=times;i++){int **a;
        if(i==2){
            cin >> cur_row1 >> cur_col1;

            a=new int* [cur_row1];
            for(int i=0;i<cur_row1;i++){
                a[i]=new int[cur_col1];
            }
            for(int i=0;i<cur_row1;i++) {
                for (int j = 0; j < cur_col1; j++) {
                    cin >> in_num;
                    a[i][j] = in_num;
                }
            }
        }else{
            cur_col1 = cur_col2;
            a=new int* [cur_row1];
            for(int i=0;i<cur_row1;i++){
                a[i]=new int[cur_col1];
            }
            for(int i=0;i<cur_row1;i++) {
                for (int j = 0; j < cur_col1; j++) {
                    a[i][j]=p[i][j];

                }
            }
        }//输入第一个数组

        cin >> cur_row2 >> cur_col2;
        int **b;
        b=new int* [cur_row2];
        for(int i=0;i<cur_row2;i++){
            b[i]=new int[cur_col2];
        }
        for(int i=0;i<cur_row2;i++){
            for(int j=0;j<cur_col2;j++){
                cin >> in_num;
                b[i][j]=in_num;
            }
        }
        p= matrix_multi(a,b,cur_row1,cur_row2,cur_col1,cur_col2);//p即为得到的新数组

    }
    for(int i=0;i<cur_row1;i++){
        for(int j=0;j<cur_col2;j++){
            if(j!=cur_col2-1){
                cout << p[i][j] << " ";
            }else{
                cout << p[i][j];
            }
        }
        cout << '\n';
    }
    return 0;
}
int** matrix_multi(int **a,int **b,int row1,int row2,int col1,int col2){
    int** c;
    c=new int* [row1];
    for(int i=0;i<row1;i++){
        c[i]=new int[col2];
    }
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            c[i][j]=0;
        }
    }
//    cout << a[1][1];
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            for(int k=0;k<col1;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return c;
}