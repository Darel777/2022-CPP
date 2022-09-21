#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class character{
public:
    int type;// 1 warrior 2 magician 3 leader
    int hp;
    int atk;
    int ultimate=1;// for 2 defense
    character(int type);
};
character::character(int type) {
    this->type=type;
    if(this->type==1){
        this->hp=12;this->atk=2;
    }else if(this->type==2){
        this->hp=2;this->atk=6;
    }else{
        this->hp=6;this->atk=6;
    }
}
int main() {
    int red_itr=0;int blue_itr=0;
    vector<character> red;
    vector<character> blue;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int demo1_type;
        cin >> demo1_type;
        character demo1=character(demo1_type);
        red.emplace_back(demo1);
    }
    for(int i=0;i<N;i++){
        int demo2_type;
        cin >> demo2_type;
        character demo2=character(demo2_type);
        blue.emplace_back(demo2);
    }
    while(1){//battling
        //计算结果
        if(red_itr==red.size()&&blue_itr!=blue.size()){
            for(int i=blue_itr;i<blue.size();i++){
                cout << blue[i].type << blue[i].atk << blue[i].hp;
                if(i!=blue.size()-1){
                    cout << endl;
                }
            }
            break;
        }else if(blue_itr==blue.size()&&red_itr!=red.size()){
            for(int i=red_itr;i<red.size();i++){
                cout << red[i].type << red[i].atk << red[i].hp;
                if(i!=red.size()-1){
                    cout << endl;
                }
            }
            break;
        }else if(blue_itr==blue.size()&&red_itr==red.size()){
            cout << "All Dead" << endl;
            break;
        }
        //模拟战斗
        red[red_itr].hp-=blue[blue_itr].atk;
        blue[blue_itr].hp-=red[red_itr].atk;
        if(red[red_itr].type==2&&red[red_itr].ultimate==1){
            red[red_itr].ultimate=0;
            red[red_itr].hp+=blue[blue_itr].atk;//先减再加等于没扣血量
        }
        if(blue[blue_itr].type==2&&blue[blue_itr].ultimate==1){
            blue[blue_itr].ultimate=0;
            blue[blue_itr].hp+=red[red_itr].atk;//先减再加等于没扣血量
        }
        if(red[red_itr].hp>0){
            if(red[red_itr].type==1){
                red[red_itr].hp+=1;
            }else if(red[red_itr].type==3){
                red[red_itr].atk+=1;
            }
        }else{
            red_itr=red_itr+1;
        }
        if(blue[blue_itr].hp>0){
            if(blue[blue_itr].type==1){
                blue[blue_itr].hp+=1;
            }else if(blue[blue_itr].type==3){
                blue[blue_itr].atk+=1;
            }
        }else{
            blue_itr=blue_itr+1;
        }
        int k=0;
    }

}
