#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class rectangle{
public:
    string id="";
    int red=0;
    int green=0;
    int blue=0;
    int mode=0;
    vector<string> attr_group;//所隶属的组
    rectangle(int mode,string id);
    void set_color(int red, int green, int blue);
};
rectangle::rectangle(int mode,string id) {
    this->mode=mode;
    this->id=id;
}
void rectangle::set_color(int red, int green, int blue) {//mode0 正常矩形 mode1 反色矩形 mode2 单红色矩形
    if(mode==0){
        this->red=red;this->green=green;this->blue=blue;
    }else if(mode==1){
        this->red=255-red;this->green=255-green;this->blue=255-blue;
    }else if(mode==2){
        this->red=red;
    }
}
bool com1(rectangle r1,rectangle r2){
    int r1_index= atoi(r1.id.substr(1).c_str());
    int r2_index= atoi(r2.id.substr(1).c_str());
    return r1_index<r2_index;
}
bool com2 (rectangle r1,rectangle r2){
    double r1_index=0.299*r1.red+0.587*r1.green+0.114*r1.blue;
    double r2_index=0.299*r2.red+0.587*r2.green+0.114*r2.blue;
    if(r1_index<r2_index){
        return true;
    }else if(r1_index>r2_index){
        return false;
    }else{
        return com1(r1,r2);
    }
}
int main() {
    vector<rectangle> rectangles;
    int N;
    cin >> N;
    cin.get();
    for(int p=0;p<N;p++){
        string instruction;
        cin >> instruction;
        if(instruction=="Add"){
            int mode; string id;
            string instruction2;
            cin >>instruction2;
            if(instruction2=="normal"){
                mode=0;
            }else if(instruction2=="single"){
                mode=2;
            }else if(instruction2=="reverse"){
                mode=1;
            }
            cin >>instruction2;
            rectangle demo=rectangle(mode,instruction2);
            rectangles.emplace_back(demo);
        }else if(instruction=="Group"){
            int numbers;
            cin >>numbers;
            vector<string> temp;
            for(int i=0;i<numbers;i++){
                string to_set;
                cin >>to_set;
                temp.emplace_back(to_set);
            }//temp装有将要成组的全部编号
            string group_id;
            cin >> group_id;
            for(int i=0;i<rectangles.size();i++){
                for(int j=0;j<temp.size();j++){
                    if(rectangles[i].id==temp[j]){
                        rectangles[i].attr_group.emplace_back(group_id);
                        break;
                    }
                }
            }
        }else if(instruction=="Set") {
            string target;
            cin >> target;
            int red;int green;int blue;
            cin >>red; cin >>green;cin >> blue;
            if(target[0]=='G'){
                for(int i=0;i<rectangles.size();i++){
                    for(int j=0;j<rectangles[i].attr_group.size();j++){
                        if(rectangles[i].attr_group[j]==target){
                            rectangles[i].set_color(red,green,blue);
                        }
                    }
                }
            }else if(target[0]=='P'){
                for(int i=0;i<rectangles.size();i++){
                    if(rectangles[i].id==target){
                        rectangles[i].set_color(red,green,blue);
                    }
                }
            }
        }else{
            cout << "error0";
        }
    }
    string final;
    cin >> final;
    if(final=="Normal"){
        sort(rectangles.begin(),rectangles.end(),com1);
        for(int i=0;i<rectangles.size();i++){
            cout << rectangles[i].id << " " << rectangles[i].red <<" " << rectangles[i].green<< " " << rectangles[i].blue<< endl;
        }
    }else if(final=="Gray"){
        sort(rectangles.begin(),rectangles.end(),com2);
        for(int i=0;i<rectangles.size();i++){
            cout << rectangles[i].id << " " << rectangles[i].red <<" " << rectangles[i].green<< " " << rectangles[i].blue<< endl;
        }
    }else{
        cout << "error1";
    }
}
