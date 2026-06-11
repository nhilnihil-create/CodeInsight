#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    string s;
    cin>>s;
    size_t l=s.length();
    map<string,ll> dict;
    rep(i,26) dict[string(1,'a'+i)]=0;
    bool flag=false;
    string ans;
    rep(i,l) dict[string(1,s[i])]++;
    rep(i,26){
        if(dict[string(1,'a'+i)]==0){
            ans=string(1,'a'+i);
            flag=true;
            break;
        }
    }
    if(flag) cout<<ans<<"\n";
    else cout<<"None"<<"\n";
    return 0;
}