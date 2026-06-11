#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll mod=1e+9+7;
int main(void){
    ll n;cin>>n;
    ll res=1;
    map<ll,ll> mp;
    for(ll i=2;i<=n;i++){
        ll now=i;
        for(ll j=2;j<=sqrt(now);j++){
            while(now%j==0){
                mp[j]++;
                now/=j;
            }
        }
        if(now>1)mp[now]++;
    }
    for(auto& p:mp){
        res*=(p.second+1);
        res%=mod;
    }
    cout<<res<<endl;
}