#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll res=1e10;
    if(n==k){
        ll tmp=0;
        ll nax=0;
        rep(i,n){
            if(nax>=a[i]){
                tmp+=nax-a[i]+1;
                nax++;
            }
            chmax(nax, a[i]);
        }
        cout<<tmp<<endl;
        return 0;
    }

    rep(i, 1<<n){
        ll num=0;
        rep(j,n){
            if((i>>j) & 1) num++;
        }
        if(num<k) continue;
        ll tmp=0;
        ll nax=0;
        rep(j,n){
            if((i>>j) & 1){
                if(nax>=a[j]){
                    tmp+=nax-a[j]+1;
                    nax++;
                }
            }
            chmax(nax, a[j]);
        }
        chmin(res, tmp);
    }
    cout<<res<<endl;
    return 0;
}