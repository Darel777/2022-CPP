#include <iostream>
using namespace std;
class XOQ{//一个单子
public:
    int size =0;//棋盘长、宽
    int order = 0;//几子连环
    int completed = 0;//已经下了几个子
    int tick=0;//判断该下什么子 0是O 1是X
    int** board;//棋盘
    XOQ(int size,int order);//构造
    int judge();//判断棋局是否有人赢了
    void put(int x,int y);//下子
};
XOQ::XOQ(int size, int order) {
    this->size=size;
    this->order=order;
    board=new int* [size];
    for(int i=0;i<size;i++){
        board[i]=new int[size];
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            board[i][j]=-1;//init
        }
    }
}
int XOQ::judge() {
//    for(int i=0;i<size;i++){
//
//        for(int j=0;j<size;j++){
//            cout << board[i][j];
//        }
//        cout <<endl;
//    }
    //判断横向 3
    for(int i=0;i<size;i++){
        for(int j=0;j<=size-order;j++){
            int combo=1;int k=j;
            while(board[i][k]==board[i][k+1]){
                combo=combo+1;k=k+1;
                if(combo==order){
                    break;
                }
            }
            if(combo>=order){
                if(board[i][k]==0){
                    cout << "O Success" << endl;
                    return 1;
                }else if(board[i][k]==1){
                    cout << "X Success" << endl;
                    return 1;
                }
            }
        }
    }
    //判断纵向 2
    for(int j=0;j<size;j++){
        for(int i=0;i<=size-order;i++){
            int combo=1;int k=i;
            while(board[k][j]==board[k+1][j]){
                combo=combo+1;k=k+1;
                if(combo==order){
                    break;
                }
            }
            if(combo>=order){
                if(board[k][j]==0){
                    cout << "O Success" << endl;
                    return 1;
                }else if(board[k][j]==1){
                    cout << "X Success" << endl;
                    return 1;
                }
            }
        }
    }
    //判断左上-右下 3
    for(int i=0;i<=size-order;i++){
        for(int j=0;j<=size-order;j++){
            int combo=1;int k=i;int l=j;
            while(board[k][l]==board[k+1][l+1]){
                combo=combo+1;k=k+1;l=l+1;
                if(combo==order){
                    break;
                }
            }
            if(combo>=order){
                if(board[k][l]==0){
                    cout << "O Success" << endl;
                    return 1;
                }else if(board[k][l]==1){
                    cout << "X Success" << endl;
                    return 1;
                }
            }
        }
    }
    //判断右上-左下
    for(int j=size-1;j>=order-1;j--){
        for(int i=0;i<=size-order;i++){
            int combo=1;int k=i;int l=j;
            while(board[k][l]==board[k+1][l-1]){
                combo=combo+1;k=k+1;l=l-1;
                if(combo==order){
                    break;
                }
            }
            if(combo>=order){
                if(board[k][l]==0){
                    cout << "O Success" << endl;
                    return 1;
                }else if(board[k][l]==1){
                    cout << "X Success" << endl;
                    return 1;
                }
            }
        }
    }
    if(completed==size*size){//2
        cout << "Dogfall" << endl;
        return 1;
    }
    return 0;
}
void XOQ::put(int x,int y) {
    this->board[x][y]=this->tick;
    if(this->tick==0){
        this->tick=1;
    }else{
        this->tick=0;
    }
    this->completed+=1;
}
int main() {
    int size;
    int order;
    cin >> size;
    cin >> order;
    XOQ *xoq=new XOQ(size,order);
    while(1){
        int x;
        int y;
        cin >>x;
        cin >>y;
        xoq->put(x,y);
        int success=xoq->judge();
        if(success){
            break;
        }
    }
}
