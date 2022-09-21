#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;
class User{
    public:
        int userid;
        int weibo_count[100][3]={0};//第一个 微博id 第二个 微博type 第三个 微博时间戳
        int i_sub[100]={0};//我的关注
    User(int uid);

};
User::User(int uid) {
    this->userid=uid;
}
bool com1(pair<int,int> a,pair<int,int> b){
    if(a.second>b.second){
        return true;
    }else{
        return false;
    }
}
int main() {
    vector<User> users;//users container

    int N;
    cin >> N;
    cin.get();
    int timestamp=1;

    for(int p=0;p<N;p++){
        string instruction;
        cin >>instruction;
        if(instruction=="post"){
//            cout << "post" << endl;
            int userid;int weiboid;int type;
            cin >>userid; cin>> weiboid;cin >>type;

            bool is_new=true;//判断是不是新用户

            for(int i=0;i<users.size();i++){
                if(users[i].userid==userid){
                    is_new=false;
                    for(int j=0;j<100;j++){
                        if(users[i].weibo_count[j][0]==0){
                            users[i].weibo_count[j][0]=weiboid;
                            users[i].weibo_count[j][1]=type;
                            users[i].weibo_count[j][2]=timestamp;
                            timestamp=timestamp+1;
                            break;
                        }
                    }
                    break;
                }
            }
            if(is_new){
                User user=User(userid);
                users.emplace_back(user);
                for(int i=0;i<users.size();i++){
                    if(users[i].userid==userid){
                        is_new=false;
                        for(int j=0;j<100;j++){
                            if(users[i].weibo_count[j][0]==0){
                                users[i].weibo_count[j][0]=weiboid;
                                users[i].weibo_count[j][1]=type;
                                users[i].weibo_count[j][2]=timestamp;
                                timestamp=timestamp+1;
                                break;
                            }
                        }
                        break;
                    }
                }
            }

        }else if(instruction=="follow"){
//            cout << "follow" << endl;
            int follower;int followee;
            cin >> follower;cin >> followee;

            bool is_new=true;
            for(int i=0;i<users.size();i++){
                if(users[i].userid==follower){
                    is_new=false;
                }
            }
            if(is_new){
                User user=User(follower);
                users.emplace_back(user);
            }
            is_new=true;
            for(int i=0;i<users.size();i++){
                if(users[i].userid==followee){
                    is_new=false;
                }
            }
            if(is_new){
                User user=User(followee);
                users.emplace_back(user);
            }

            for(int i=0;i<users.size();i++){
                if(users[i].userid==follower){
                    for(int j=0;j<100;j++){
                        if(users[i].i_sub[j]==0){
                            users[i].i_sub[j]=followee;
                            break;
                        }
                    }
                    break;
                }
            }
        }else if(instruction=="unfollow"){
//            cout << "unfollow" << endl;
            int follower;int followee;
            cin >> follower;cin >> followee;
            bool is_new=true;
            for(int i=0;i<users.size();i++){
                if(users[i].userid==follower){
                    is_new=false;
                }
            }
            if(is_new){
                User user=User(follower);
                users.emplace_back(user);
            }
            is_new=true;
            for(int i=0;i<users.size();i++){
                if(users[i].userid==followee){
                    is_new=false;
                }
            }
            if(is_new){
                User user=User(followee);
                users.emplace_back(user);
            }
            for(int i=0;i<users.size();i++){
                if(users[i].userid==follower){
                    for(int j=0;j<100;j++){
                        if(users[i].i_sub[j]==followee){
                            users[i].i_sub[j]=0;
                            break;
                        }
                    }
                    break;
                }
            }
        }else if(instruction=="getFollows"){
//            cout << "getFollows" << endl;
            int userid;
            cin >> userid;
            bool is_new=true;
            for(int i=0;i<users.size();i++){
                if(users[i].userid==userid){
                    is_new=false;
                }
            }
            if(is_new){
                User user=User(userid);
                users.emplace_back(user);
            }
            int sum=0;
            for(int i=0;i<users.size();i++){
                if(users[i].userid==userid){
                    for(int j=0;j<100;j++){
                        if(users[i].i_sub[j]!=0){
                            sum=sum+1;
                        }
                    }
                    cout << sum << endl;
                    break;
                }
            }
        }else if(instruction=="getFans"){
//            cout << "getFans" << endl;
            int userid;
            cin >> userid;
            bool is_new=true;
            for(int i=0;i<users.size();i++){
                if(users[i].userid==userid){
                    is_new=false;
                }
            }
            if(is_new){
                User user=User(userid);
                users.emplace_back(user);
            }
            int sum=0;
            for(int i=0;i<users.size();i++){
                for(int j=0;j<100;j++){
                    if(users[i].i_sub[j]==userid){
                        sum=sum+1;
                    }
                }
            }
            cout << sum << endl;
        }else if(instruction=="getWeibos"){
//            cout << "getWeibos" << endl;
            int userid;
            cin >> userid;
            bool is_new=true;
            for(int i=0;i<users.size();i++){
                if(users[i].userid==userid){
                    is_new=false;
                }
            }
            if(is_new){
                User user=User(userid);
                users.emplace_back(user);
            }
            for(int i=0;i<users.size();i++){
                if(users[i].userid==userid){
                    for(int j=0;j<100;j++){
                        if(users[i].weibo_count[j][0]==0){
                            cout << j << endl;
                            break;
                        }
                    }
                    break;
                }
            }
        }else if(instruction=="getRecent") {
            int userid;
            int num;
            int type;
            cin >> userid;
            cin >> num;
            cin >> type;
            bool is_new = true;
            for (int i = 0; i < users.size(); i++) {
                if (users[i].userid == userid) {
                    is_new = false;
                }
            }
            if (is_new) {
                User user = User(userid);
                users.emplace_back(user);
            }

            if (type == 0) {
                for (int i = 0; i < users.size(); i++) {
                    if (users[i].userid == userid) {
                        int check = -1;
                        for (int j = 0; j < 100; j++) {
                            if (users[i].weibo_count[j][0] == 0) {
                                check = j;
                                break;
                            }
                        }
                        for (int j = check - 1; num > 0; num--) {
                            cout << users[i].weibo_count[j][0] << " ";
                            j = j - 1;
                            if(j<0){
                                break;
                            }
                        }
                        cout << endl;
                        break;
                    }
                }
            } else if (type == 1) {
                vector<pair<int, int>> oks;
                for (int i = 0; i < users.size(); i++) {
                    if (users[i].userid == userid) {
                        for (int j = 0; j < 100; j++) {
                            if (users[i].weibo_count[j][0] != 0) {
                                pair<int, int> p = make_pair(users[i].weibo_count[j][0], users[i].weibo_count[j][2]);
                                oks.emplace_back(p);
                            } else {
                                break;
                            }
                        }//先加自己的
                        for (int j = 0; j < 100; j++) {
                            int followee = users[i].i_sub[j];
                            if (followee == 0) {
                                break;
                            }
                            for (int k = 0; k < users.size(); k++) {
                                if (users[k].userid == followee) {
                                    bool is_dual = false;
                                    for (int l = 0; l < 100; l++) {
                                        if (users[k].i_sub[l] == userid) {
                                            is_dual = true;
                                        }
                                    }
                                    if (is_dual) {
                                        for (int l = 0; l < 100; l++) {
                                            if (users[k].weibo_count[l][0] != 0) {
                                                if (users[k].weibo_count[l][1] == 2 ||
                                                    users[k].weibo_count[l][1] == 1) {
                                                    pair<int, int> p = make_pair(users[k].weibo_count[l][0],
                                                                                 users[k].weibo_count[l][2]);
                                                    oks.emplace_back(p);
                                                }
                                            } else {
                                                break;
                                            }
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
                sort(oks.begin(),oks.end(),com1);
                for (int i = 0; num >0; num--) {
                    cout << oks[i].first ;
                    i=i+1;
                    if(i==oks.size()){
                        cout << endl;
                        break;
                    }else{
                        cout << " ";
                    }

                }

            } else if (type == 2) {
                vector<pair<int, int>> oks;
                for (int i = 0; i < users.size(); i++) {
                    if (users[i].userid == userid) {
                        for (int j = 0; j < 100; j++) {
                            if (users[i].weibo_count[j][0] != 0) {
                                pair<int, int> p = make_pair(users[i].weibo_count[j][0], users[i].weibo_count[j][2]);
                                oks.emplace_back(p);
                            } else {
                                break;
                            }
                        }//先加自己的
                        for (int j = 0; j < 100; j++) {
                            int followee = users[i].i_sub[j];
                            if (followee == 0) {
                                break;
                            }
                            for (int k = 0; k < users.size(); k++) {
                                if (users[k].userid == followee) {
                                    for (int l = 0; l < 100; l++) {
                                        if (users[k].weibo_count[l][0] != 0) {
                                            if (users[k].weibo_count[l][1] == 2) {
                                                pair<int, int> p = make_pair(users[k].weibo_count[l][0],
                                                                             users[k].weibo_count[l][2]);
                                                oks.emplace_back(p);
                                            }
                                            if (users[k].weibo_count[l][1] == 1) {
                                                bool is_dual = false;
                                                for (int aa = 0; aa < 100; aa++) {
                                                    if (users[k].i_sub[aa] == userid) {
                                                        is_dual = true;
                                                    }
                                                }
                                                if (is_dual) {
                                                    pair<int, int> p = make_pair(users[k].weibo_count[l][0],
                                                                                 users[k].weibo_count[l][2]);
                                                    oks.emplace_back(p);
                                                }
                                            }
                                        } else {
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
                sort(oks.begin(),oks.end(),com1);
                for (int i = 0; num >0; num--) {
                    cout << oks[i].first ;
                    i=i+1;
                    if(i==oks.size()){
                        cout << endl;
                        break;
                    }else{
                        cout << " ";
                    }

                }

            }
        }



    }
}

