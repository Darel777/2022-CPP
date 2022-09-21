#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class rectangle{
public:
    string id;
    int clr_red;
    int clr_green;
    int clr_blue;
    bool is_reverse= false;
    bool is_single_red=false;
    rectangle(string id,int mode){//mode0 default mode1 reverse mode2 single red
        if(mode==2){this->is_reverse= true;}
        if(mode==1){this->is_single_red= true;}
        this->id=id;
        this->clr_blue=this->clr_green=this->clr_red=0;
    }
    void fill(int red,int green,int blue){
        if(is_reverse){
            this->clr_red=255-red;this->clr_green=255-green;this->clr_blue=255-blue;
        }else if(is_single_red){
            this->clr_red=red;this->clr_green=this->clr_blue=0;
        }else{
            this->clr_blue=blue;this->clr_green=green;this->clr_red=red;
        }
    }
};
class rect_group{
public:
    string members;
    rect_group(string members){
        this->members=members;
    }
};
bool sort_rule1(rectangle a,rectangle b) {//根据编号排序
    return atoi(a.id.substr(1).c_str())<atoi(b.id.substr(1).c_str());
};
bool sort_rule2(rectangle a,rectangle b) {//根据灰度排序
    double a_i=((double)a.clr_red)*0.299+(double)a.clr_green*0.587+(double)a.clr_blue*0.114;
    double b_i=(double)b.clr_red*0.299+(double)b.clr_green*0.587+(double)b.clr_blue*0.114;
    if(a_i!=b_i){
        return a_i<b_i;
    }else{
        return atoi(a.id.substr(1).c_str())<atoi(b.id.substr(1).c_str());
    }
};
int main() {
    int instructions;
    cin >> instructions;
    string zancun;
    getline(cin,zancun);
    vector<rectangle> rectangle_container;
    vector<rect_group> group_container;
    for(int m=0;m<instructions;m++){
        string instruction;
        getline(cin,instruction);

        if(instruction.substr(0,3)=="Add"){//add rectangle
            int second_space=instruction.find(" ",4);
            string temp=instruction.substr(4,6);
            string id=instruction.substr(second_space+1);
            if(id[id.length()-1]=='\r'){
                id=id.substr(0,id.length()-1);
            }

            int mode;
            if(temp.find("normal")!=-1){
                mode=0;
            }else if(temp.find("single")!=-1){
                mode=1;
            }else{
                mode=2;
            }
            rectangle_container.emplace_back(rectangle(id,mode));
        }else if(instruction.substr(0,3)=="Set"){//set color
            int second_space=instruction.find(" ",4);
            int third_space=instruction.find(" ",second_space+1);
            int fourth_space=instruction.find(" ",third_space+1);
            int red= atoi(instruction.substr(second_space+1,third_space).c_str());
            int green= atoi(instruction.substr(third_space+1,fourth_space).c_str());
            int blue= atoi(instruction.substr(fourth_space+1).c_str());
            string index=instruction.substr(4,second_space-4);//判断是成组还是成个
            if(index.find("P")!=-1){//找到了P
                for(int i=0;i<rectangle_container.size();i++){
                    if(rectangle_container[i].id.find(index)!=-1){
                        rectangle_container[i].fill(red,green,blue);
                    }
                }
            }else{
                for(int i=0;i<group_container.size();i++){
                    if(group_container[i].members.find(index)!=-1){//第i个为指定小组
                        for(int j=0;j<rectangle_container.size();j++){
                            if(group_container[i].members.find(rectangle_container[j].id)!=-1){
                                rectangle_container[j].fill(red,green,blue);
                            }
                        }
                    }
                }
            }
        }else{//make a group

            int second_space=instruction.find(" ",6);
            string member=instruction.substr(second_space+1);
            group_container.emplace_back(member);
        }
    }
    string out;
    getline(cin,out);
    if(out.find("Normal")!=-1){
        sort(rectangle_container.begin(),rectangle_container.end(), sort_rule1);
        for(int i=0;i<rectangle_container.size();i++){
            cout << rectangle_container[i].id << " " << rectangle_container[i].clr_red << " " << rectangle_container[i].clr_green << " " << rectangle_container[i].clr_blue << endl;
        }
    }else{//Gray
        sort(rectangle_container.begin(),rectangle_container.end(), sort_rule2);
        for(int i=0;i<rectangle_container.size()-1;i++){
            if(((double)rectangle_container[i].clr_red*0.299+(double)rectangle_container[i].clr_green*0.587+(double)rectangle_container[i].clr_blue*0.114)>((double)rectangle_container[i+1].clr_red*0.299+(double)rectangle_container[i+1].clr_green*0.587+(double)rectangle_container[i+1].clr_blue*0.114)){
                rectangle a=rectangle_container[i];
                rectangle_container[i]=rectangle_container[i+1];
                rectangle_container[i+1]=a;
            }
        }
        for(int i=0;i<rectangle_container.size();i++){
            cout << rectangle_container[i].id << " " << rectangle_container[i].clr_red << " " << rectangle_container[i].clr_green << " " << rectangle_container[i].clr_blue << endl;
        }
    }

}
