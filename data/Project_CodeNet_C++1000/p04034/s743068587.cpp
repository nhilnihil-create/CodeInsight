#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n,m;cin >>n>>m;
    vector<bool>ch(n,false);
    ch[0]=true;
    vector<ll>cnt(n,1);
    for (int i = 0; i < m; ++i) {
        ll x,y;cin >>x>>y;
        x--;y--;
        cnt[x]--;
        cnt[y]++;
        if(ch[x]){
            ch[y]=true;
            if(cnt[x]==0)ch[x]=false;
        }
    }
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        if(ch[i])ans++;
    }
    cout <<ans <<endl;
}

