#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)

int main(){
    string s,t;
    cin>>s;

    int i=0;
    bool judge=true;

    while(t.size()<s.size()){
        if(s.substr(i,5)=="dream"){
            t+="dream";
            i+=5;
            if(s.substr(i,2)=="er"){
                if(s[i+2]=='a'){
                    continue;
                }else{
                    t+="er";
                    i+=2;
                }
            }
        }else if(s.substr(i,6)=="eraser"){
            t+="eraser";
            i+=6;
        }else if(s.substr(i,5)=="erase"){
            t+="erase";
            i+=5;
        }else{
            judge=false;
            break;
        }
    }

    cout<<(judge ? "YES" : "NO")<<endl;
}