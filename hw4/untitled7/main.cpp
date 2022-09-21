#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class car{
public:
    string id;
    double size;
    int time;
    int park_time;//停车时间
    int wait_time;//等待时间
    double fee;//费用
    double position1;//位置1
    double position2;//位置2
    car(string id,int type,int time);
};
car::car(string id, int type,int time) {
    this->id=id;
    if(type==1){
        this->size=1;this->park_time=3;this->wait_time=1;this->fee=1.5;this->time=time;
    }else if(type==2){
        this->size=1.5;this->park_time=2;this->wait_time=2;this->fee=3;this->time=time;
    }else{
        this->size=2;this->park_time=1;this->wait_time=3;this->fee=4.5;this->time=time;
    }
}
bool com1(car c1,car c2){
    return c1.position1<c2.position1;
}
void settings(vector<car> park,vector<car> wait_line,string weather,int N);
int main() {
    vector<car> park;//存放于停车场的车子
    vector<car> wait_line;//存放于等待区的车子
    int N;
    cin >> N; //N是停车位数目
    string weather;
    cin >>weather;//weather 天气
    int time_tick=1;
    while(1){
        string instruction;
        cin >> instruction;
        if(instruction=="end"){
            break;
        }else if(instruction=="in"){
            string type;
            string id;
            cin>>type;cin>>id;
            if(type=="S"){
                car demo=car(id,1,time_tick);
                wait_line.emplace_back(demo);
            }else if(type=="M"){
                car demo=car(id,2,time_tick);
                wait_line.emplace_back(demo);
            }else{
                car demo=car(id,3,time_tick);
                wait_line.emplace_back(demo);
            }
            time_tick+=1;
        }
    }
    settings(park,wait_line,weather,N);
}
void settings(vector<car> park,vector<car> wait_line,string weather,int N){
    int time_tick=1;double sum=0;
    while(1){
        //上车策略
        if(weather=="sunny"){
            double accounted=0;
            for(int i=0;i<park.size();i++){
                accounted+=park[i].size;
            }
            if(wait_line[0].size<=N-accounted){
                if(wait_line[0].time<=time_tick){
                    park.emplace_back(wait_line[0]);
                    wait_line.erase(wait_line.begin());
                }
            }
        }else if(weather=="rainy"){
            if(park.size()==0){
                if(wait_line[0].time<=time_tick){
                    park.emplace_back(wait_line[0]);
                    wait_line.erase(wait_line.begin());
                    park[0].position1=0;
                    park[0].position2=park[0].size;
                }
            }else{
                for(int i=0;i<park.size();i++){
                    if(i==0){
                        if(park[i].position1>=wait_line[0].size){
                            if(wait_line[0].time<=time_tick){
                                double front=0;
                                double end=wait_line[0].size;
                                park.emplace_back(wait_line[0]);
                                wait_line.erase(wait_line.begin());
                                park[park.size()-1].position1=front;
                                park[park.size()-1].position2=end;
                            }
                        }
                    }//头一个要判断左边
                    if(i>=0&&i<park.size()-1){
                        if(park[i+1].position1-park[i].position2>=wait_line[0].size){
                            if(wait_line[0].time<=time_tick){
                                double front=park[i].position2;
                                double end=park[i].position2+wait_line[0].size;
                                park.emplace_back(wait_line[0]);
                                wait_line.erase(wait_line.begin());
                                park[park.size()-1].position1=front;
                                park[park.size()-1].position2=end;
                            }
                        }
                    }
                    if(i==park.size()-1){
                        if(N-park[park.size()-1].position2>=wait_line[0].size){
                            if(wait_line[0].time<=time_tick){
                                double front=park[park.size()-1].position2;
                                double end=park[park.size()-1].position2+wait_line[0].size;
                                park.emplace_back(wait_line[0]);
                                wait_line.erase(wait_line.begin());
                                park[park.size()-1].position1=front;
                                park[park.size()-1].position2=end;
                            }
                        }
                    }

                }
            }
            sort(park.begin(),park.end(),com1);
        }
        if(park.size()!=0){
            for(int i=0;i<park.size();i++){
                cout << park[i].id;
                if(i!=park.size()-1){
                    cout << " ";
                }
            }
            cout << endl;
        }else{
            cout << "null" << endl;
        }

        if(park.size()!=0){
            for(auto i=park.begin();i<=park.end();i++){
                if(i->time<=time_tick){
                    i->park_time=i->park_time-1;
                }
                if(i->park_time==0){
                    sum+=i->fee;
                    park.erase(i);
                    i--;
                }
            }
        }
        if(wait_line.size()!=0){
            for(auto i=wait_line.begin();i<=wait_line.end();i++){
                if(i->time<=time_tick){
                    i->wait_time=i->wait_time-1;
                }
                if(i->wait_time==0){
                    wait_line.erase(i);
                    i--;
                }
            }
        }
        time_tick= time_tick+1;
        if(park.size()==0&&wait_line.size()==0){
            cout << "null" << endl;
            cout << sum << endl;
            break;
        }
    }
}