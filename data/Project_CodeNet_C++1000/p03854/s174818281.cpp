#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

int check_string(string &S, int pos){
    vector<string> candidates;
    candidates.push_back("dream");
    candidates.push_back("dreamer");
    candidates.push_back("erase");
    candidates.push_back("eraser");

    if(S.size()-pos<=7){
        int res = S.size()-pos;
        if(res==7){
            if(S.substr(pos, 7)=="dreamer"){
                return 1;
            }else{
                return -1;
            }
        }
        if(res==5){
            if(S.substr(pos, 5)=="dream" || S.substr(pos,5)=="erase"){
                return 1;
            }else{
                return -1;
            }
        }
        if(res==6){
            if(S.substr(pos, 6)=="eraser" ){
                return 1;
            }else{
                return -1;
            }
        }
        /*
        for(int i=0;i<candidates.size();i++){
            if(S.substr(pos, candidates.at(i).size())==candidates.at(i)){
                if(res==candidates.at(i).size()){
                    return 1;
                }else{
                    return -1;
                }
            }
        }
        return -1;
        */
    }



    int flag = 0;
    for(int i=0;i<candidates.size();i++){
        if(S.substr(pos, candidates.at(i).size())==candidates.at(i)){
            int temp = check_string(S, pos+candidates.at(i).size());
            if(temp==1)flag=1;
        }
    }
    if(flag==1){
        return 1;
    }else{
        return -1;
    }

}

signed main(){
    string S; cin>>S;

    int top_pos = 0;
    int lnegth = S.size();

    int check = check_string(S,top_pos);
    if(check==1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;

    }


    return 0;
}