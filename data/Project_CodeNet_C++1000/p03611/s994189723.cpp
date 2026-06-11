#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    map<ll,ll> mp;
    rep(i,n){
        int a;cin>>a;
        mp[a]++;
        mp[a-1]++;
        mp[a+1]++;
    }
    ll res=0;
    for(auto& p:mp)chmax(res,p.second);
    cout<<res<<endl;
}