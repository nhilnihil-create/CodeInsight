#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,m;cin>>n>>m;
    vector<ll> t(n,1);
    vector<bool> used(n,false);
    used[0]=true;
    rep(i,m){
        int x,y;cin>>x>>y;x--;y--;
        if(used[x])used[y]=true;
        if(t[x]==1)used[x]=false;
        t[x]--;t[y]++;
    }
    ll res=0;
    rep(i,n)if(used[i])res++;
    cout<<res<<endl;
}