#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    ll n,m;
    cin>>n>>m;
    vector<bool>s(200010,false);
    vector<bool>t(200010,false);
    rep(i,m){
        ll a,b;
        cin>>a>>b;
        if(a==1)s[b]=true;
        if(b==n)t[a]=true;
    }
    rep(i,200010){
        if(s[i] && t[i]){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

