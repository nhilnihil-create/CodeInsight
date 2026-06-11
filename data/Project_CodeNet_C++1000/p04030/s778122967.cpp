#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    string S;
    cin>>S;
    
    string ans=S;
    int t=0,tt=0;
    for(int i=0;i<S.length();++i){
        if(S[i]=='B'){
            if(i+t<=0){
                t-=1;
            }else{
                t-=2;
            }
        }else{
            ans[i+t]=S[i];
        }
    }
    ans = ans.substr(0,max(1,(int)ans.length()+t+tt));
    cout<<ans;
}