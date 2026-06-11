#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    string s; cin>>s;
    
    bool flg=true;
    while(flg){
        flg=false;
        int dream = s.rfind("dream");
        int dreamer = s.rfind("dreamer");
        int erase = s.rfind("erase");
        int eraser = s.rfind("eraser");

        if(5 == s.size() - dream){
            s = s.substr(0,dream);
            flg=true;
        }
        if(7 == s.size() - dreamer){
            s = s.substr(0,dreamer);
            flg=true;
        }
        if(5 == s.size() - erase){
            s = s.substr(0,erase);
            flg=true;
        }
        if(6 == s.size() - eraser){
            s = s.substr(0,eraser);
            flg=true;
        }
    }

    if(s.size()==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}
