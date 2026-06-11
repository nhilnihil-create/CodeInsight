#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    string s;
    cin>>s;
    bool fln=false;
    bool flw=false;
    bool fls=false;
    bool fle=false;
    rep(i,s.size()){
        if(s[i]=='N') fln=true;
        if(s[i]=='W') flw=true;
        if(s[i]=='S') fls=true;
        if(s[i]=='E') fle=true;
    }

    if(fln && fls){
        if(flw == fle) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
    else if(flw && fle){
        if(fln == fls) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
    else cout<<"No"<<"\n";
    return 0;
}