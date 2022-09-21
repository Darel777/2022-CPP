#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class plane{
public:
    string id;//id
    string type;//type0 battle plane type1 transport plane type2 helicopter
    int take_off;
    int task;
    int land;
    int land_first=-1;
    int join_time;
    int fly_time;
    int return_time;
    plane(string type,string id);
    void set(int take_off,int task,int land);
};
plane::plane(string type,string id) {
    this->id=id;
    this->type=type;
    if(type=="battleplane"){
        this->take_off=2;this->task=0;this->land=2;
    }else if(type=="transportplane"){
        this->take_off=3;this->task=0;this->land=3;
    }else{
        this->take_off=1;this->task=0;this->land=1;
    }
}
void plane::set(int take_off, int task, int land) {
    this->take_off=take_off;this->task=task;this->land=land;
}
bool com1(plane p1,plane p2){
    return atoi(p1.id.substr(1).c_str())<atoi(p2.id.substr(1).c_str());
}
bool com2(plane p1,plane p2){
    if(p1.join_time!=p2.join_time){
        return p1.join_time<p2.join_time;
    }else{
        if(p1.type!=p2.type){
            if(p1.type=="helicopter"){
                return true;
            }else if(p1.type=="battleplane"){
                if(p2.type=="helicopter"){
                    return false;
                }else{
                    return true;
                }
            }else{
                return false;
            }
        }else{
            return com1(p1,p2);
        }
    }
}
bool com3(plane p1,plane p2){
    if(p1.return_time!=p2.return_time){
        return p1.return_time<p2.return_time;
    }else{
        if(p1.type!=p2.type){
            if(p1.type=="transportplane"){
                return true;
            }else if(p1.type=="battleplane"){
                if(p2.type=="helicopter"){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return com1(p1,p2);
        }
    }
}
void settings(vector<plane> storage,vector<plane> platform,string mode);
int main() {
    int N;cin >>N;
    vector<plane> storage;
    vector<plane> platform;
    for(int p=0;p<N-1;p++){
        string instruction;cin >>instruction;
        if(instruction=="add"){
            string type;cin >>type;
            string id;cin >> id;
            plane demo=plane(type,id);
            storage.emplace_back(demo);
        }else if(instruction=="set"){
            string id; cin>>id;
            int fly;int task;int land;cin>>fly;cin>>task;cin>>land;
            for(int i=0;i<storage.size();i++){
                if(storage[i].id==id){
                    storage[i].set(fly,task,land);
                    break;
                }
            }
        }else if(instruction=="join"){
            string id; cin>>id;
            int time; cin>>time;
            for(int i=0;i<storage.size();i++){
                if(storage[i].id==id){
                    storage[i].join_time=time;
                    break;
                }
            }
        }else if(instruction=="landfirst"){
            int time; cin>>time;
            string id; cin>>id;
            for(int i=0;i<storage.size();i++){
                if(storage[i].id==id){
                    storage[i].land_first=time;
                    break;
                }
            }
        }else{
            cout << "error" << endl;
        }
    }
    string mode;cin>>mode;
    settings(storage,platform,mode);
}
void settings(vector<plane> storage,vector<plane> platform,string mode){
//    string id;//id
//    string type;//type0 battle plane type1 transport plane type2 helicopter
//    int take_off;
//    int task;
//    int land;
//    int land_first;
//    int join_time;
//    int fly_time;
//    int return_time;
//    plane(string type,string id);
//    void set(int take_off,int task,int land);
    int time_tick=0;bool if_use=false;int release_time;vector<plane> at_air;
    //time tick 当前时间戳 if_use 跑道是否被使用 release_time 计算跑道释放时间
    if(mode=="normal"){
        sort(storage.begin(),storage.end(),com1);
        for(int i=0;i<storage.size();i++){
            cout << storage[i].id << " "<< storage[i].type << " "<< storage[i].take_off << " "<< storage[i].task << " "<< storage[i].land << endl;
        }
    }else if(mode=="schedule"){
        while(1){
            //剔除
            for(auto i=storage.begin();i<storage.end();i++){
                if(i->join_time<time_tick){
                    storage.erase(i);
                    i--;
                }
            }
            //把时间正确的放进跑道
            for(int i=0;i<storage.size();i++){
                if(storage[i].join_time==time_tick){
                    platform.emplace_back(storage[i]);
                }
            }
            for(auto i=at_air.begin();i<at_air.end();i++){
                if(i->land_first>=0&&i->land_first<=time_tick){
                    if(!if_use){
                        i->return_time=time_tick+i->land;
                        if_use=true;release_time=time_tick+i->land;
                        cout << i->id << " " << i->fly_time << " " << i->return_time<< endl;
                        at_air.erase(i);
                    }
                }
            }

            //规划谁先起飞
            sort(platform.begin(),platform.end(),com2);
            //如果此时的跑道是空闲的，则起飞，同时记录返航时间
            if(!if_use){
                if(platform.size()>0){
                    platform[0].fly_time=time_tick;
                    platform[0].return_time=time_tick+platform[0].take_off+platform[0].task;
                    if_use=true;release_time=time_tick+platform[0].take_off;
                    at_air.emplace_back(platform[0]);
                    platform.erase(platform.begin());
                }
            }
            //规划谁先降落
            sort(at_air.begin(),at_air.end(),com3);
            //如果跑道空闲且开头的飞机该降落了 则降落
            if(!if_use){
                if(at_air.size()>0){
                    if(at_air[0].return_time<=time_tick){
                        at_air[0].return_time=time_tick+at_air[0].land;
                        if_use=true;release_time=time_tick+at_air[0].land;
                        cout << at_air[0].id << " " << at_air[0].fly_time << " " << at_air[0].return_time<< endl;
                        at_air.erase(at_air.begin());
                    }
                }
            }
            time_tick=time_tick+1;
            if(time_tick==release_time){
                if_use=false;
            }
            if(storage.size()==0&&platform.size()==0&&at_air.size()==0){
                return;
            }
        }
    }
}
