#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll x,y;cin >>x>>y;
    ll d=abs(y)-abs(x);
    ll ans=0;
    if(d>=0){
        ans+=abs(d);
        if(x<0)ans++;
        if(y<0)ans++;
    }
    else {
        ans+=abs(d);
        if(x>0)ans++;
        if(y>0)ans++;
    }
    cout <<ans <<endl;
    return 0;
}

