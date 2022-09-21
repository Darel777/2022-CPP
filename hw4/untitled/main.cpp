#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct tie_jiang{
    int uid;
    int type;
    int is_doing=0;
    int remain_time=0;
    int completed[100]={0};
};
struct bing_qi{
    int oid;
    int priority;
    int time;
    int type;
};

int main() {
    int tie_jiang_number;//几个铁匠
    int zan_cun_number;//最多允许暂存的订单数量
    int pending[100];
    cin >> tie_jiang_number;
    cin >> zan_cun_number;
    tie_jiang * tie_jiang_area=new tie_jiang[tie_jiang_number];
    bing_qi * zan_cun_area=new bing_qi[zan_cun_number];
    for(int i=0;i<tie_jiang_number;i++){
        int uid;
        int type;
        cin >> uid;
        cin >> type;
        tie_jiang_area[i].uid=uid;
        tie_jiang_area[i].type=type;
    }
    for(int i=0;i<zan_cun_number;i++){
        zan_cun_area[i].oid=0;
        zan_cun_area[i].type=0;
        zan_cun_area[i].time=0;
        zan_cun_area[i].priority=0;
    }

    int N;
    cin >> N;
    cin.get();

    for(int p=0;p<N;p++){
        //调度
        for(int i=0;i<tie_jiang_number;i++){
            if(tie_jiang_area[i].remain_time>0){
                tie_jiang_area[i].remain_time-=1;
                if(tie_jiang_area[i].remain_time==0){
                    for(int j=0;j<100;j++){
                        if(tie_jiang_area[i].completed[j]==0){
                            tie_jiang_area[i].completed[j]=tie_jiang_area[i].is_doing;
                            break;
                        }
                    }
                    tie_jiang_area[i].is_doing=0;
                }
            }
        }
        for(int i=0;i<tie_jiang_number;i++){
            if(tie_jiang_area[i].is_doing==0){
                int oid=0;int priority=0; int time=0; int type=0;
                for(int j=0;j<zan_cun_number;j++){
                    if(tie_jiang_area[i].type==zan_cun_area[j].type){
                        if(zan_cun_area[j].priority>priority){
                            oid=zan_cun_area[j].oid;
                            priority=zan_cun_area[j].priority;
                            time=zan_cun_area[j].time;
                            type=zan_cun_area[j].type;
                        }
                    }
                }
                if(oid!=0){
                    tie_jiang_area[i].is_doing=oid;
                    tie_jiang_area[i].remain_time=time;
                }
                for(int j=0;j<zan_cun_number;j++){
                    if(zan_cun_area[j].oid==oid){
                        zan_cun_area[j].oid=zan_cun_area[j].type=zan_cun_area[j].priority=zan_cun_area[j].time=0;
                        break;
                    }
                }
            }
        }

        string instructions;
        cin >> instructions;
        if(instructions=="add"){
            int oid;
            int priority;
            int time;
            int type;
            cin >>oid;
            cin >>priority;
            cin >>time;
            cin >>type;
            bool is_set=false;
            for(int j=0;j<zan_cun_number;j++){
                if(zan_cun_area[j].oid==0){
                    zan_cun_area[j].oid=oid;
                    zan_cun_area[j].type=type;
                    zan_cun_area[j].time=time;
                    zan_cun_area[j].priority=priority;
                    is_set= true;
                    break;
                }
            }
            if(!is_set){
                int sequence=-1;int priority1=INT32_MAX;
                for(int j=0;j<zan_cun_number;j++){
                    if(zan_cun_area[j].priority<priority1){
                        sequence=j;priority1=zan_cun_area[j].priority;
                    }
                }
                for(int i=0;i<100;i++){
                    if(pending[i]==0){
                        pending[i]=zan_cun_area[sequence].oid;
                        break;
                    }
                }
                if(sequence!=-1){
                    zan_cun_area[sequence].oid=oid;
                    zan_cun_area[sequence].priority=priority;
                    zan_cun_area[sequence].type=type;
                    zan_cun_area[sequence].time=time;
                }
            }
        }else if(instructions=="queryUser"){
            int tie_jiang_id;
            cin >> tie_jiang_id;
            for(int i=0;i<tie_jiang_number;i++){
                if(tie_jiang_area[i].uid==tie_jiang_id){
                    if(tie_jiang_area[i].is_doing==0){
                        cout << "worker " << tie_jiang_id << " resting" << endl;
                    }else{
                        cout << "worker " << tie_jiang_id << " doing order " << tie_jiang_area[i].is_doing<< endl;
                    }
                    break;
                }
            }
        }else if(instructions=="queryOrder"){
            int order_id;
            cin >> order_id;
            int numbers=0;
            for(int i=0;i<zan_cun_number;i++){
                if(zan_cun_area[i].oid==order_id){
                    if(numbers==0){
                        cout << "order " << order_id << " pending" << endl;
                        numbers=numbers+1;
                        break;
                    }

                }
            }
            for(int i=0;i<tie_jiang_number;i++){
                if(tie_jiang_area[i].is_doing==order_id){
                    if(numbers==0){
                        cout << "order " << order_id << " doing" << endl;
                        numbers=numbers+1;
                        break;
                    }
                }
                for(int j=0;j<100;j++){
                    if(tie_jiang_area[i].completed[j]==order_id){
                        if(numbers==0){
                            cout << "order " << order_id << " done" << endl;
                            numbers=numbers+1;
                            break;
                        }
                    }
                }
            }
            for(int i=0;i<100;i++){
                if(pending[i]==order_id){
                    if(numbers==0){
                        cout << "order " << order_id << " discarded" << endl;
                        numbers=numbers+1;
                        break;
                    }


                }
            }
        }else if(instructions=="queryOrders"){
            int tie_jiang_id;
            cin >> tie_jiang_id;
            for(int i=0;i<tie_jiang_number;i++){
                if(tie_jiang_area[i].uid==tie_jiang_id){
                    string result="";
                    for(int j=0;j<100;j++){
                        if(tie_jiang_area[i].completed[j]!=0){
                            result=result + to_string(tie_jiang_area[i].completed[j]);
                            result=result + " ";
                        }else{
                            break;
                        }
                    }
                    if(result.length()!=0){
                        result=result.substr(0,result.length()-1);
                    }
                    cout << result << endl;
                }
                break;
            }
        }


    }

}
