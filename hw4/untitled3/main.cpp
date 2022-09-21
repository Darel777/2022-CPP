#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class server{
public:
    int id;
    int weight=1;
    int orig_weight=1;
    server(int id);
};
server::server(int id){
    this->id=id;
}
//M个请求 N个服务器
int main() {
    int M;//请求数量
    int N;//服务器数量
    int S;//策略
    cin >> M; cin >> N; cin >> S;
    vector<server> servers;
    for(int i=1;i<=N;i++){
        server ser=server(i);
        servers.emplace_back(ser);
    }//根据服务器数量装填服务器
    if(S==4){
        for(int i=1;i<=N;i++){
            cin >> servers[i-1].weight;
            servers[i-1].orig_weight=servers[i-1].weight;
        }
    }//如果策略是4 则分配权重
    int check=1;
    int position=0;//0 正向
    for(int i=0;i<M;i++){
        string instruction;
        cin >> instruction;
        if(S==1){
            cout << instruction << " " << check;
            check=check+1;
            if(check>N){
                check=1;
            }
        }else if(S==2){
            cout <<instruction << " " << check;
            if(position==0){
                check=check+1;
                if(check>N){
                    check=(N-1>=1)?N-1:1;
                    position=1;
                }
            }else if(position==1){
                check=check-1;
                if(check<=0){
                    check=(N-1>=1)?2:1;
                    position=0;
                }

            }
        }else if(S==3){
            if(N==1){
                cout << instruction << " "<<check;
            }else{
                if(position==0){//0 ji shu
                    cout << instruction << " "<<check;
                    check=check+2;
                    if(check>N){
                        check=2;
                        position=1;
                    }
                }else if(position==1){
                    cout << instruction << " "<<check;
                    check=check+2;
                    if(check>N){
                        check=1;
                        position=0;
                    }
                }
            }
        }else if(S==4){
            cout << instruction << " " << check;
            servers[check-1].weight=servers[check-1].weight-1;
            if(servers[check-1].weight==0){
                servers[check-1].weight=servers[check-1].orig_weight;
                check=check+1;
                if(check>N){
                    check=1;
                }
            }


        }
    }



}
