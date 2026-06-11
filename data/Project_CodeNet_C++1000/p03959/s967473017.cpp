#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    const ll mod = 1e9 + 7;
    ll n; cin >> n;
    vector<ll> t(n), a(n), M(n, 0), m(n, 0);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> a[i];
    rep(i, n) {
        if(i==0){
            M[i]=t[i]; m[i] = t[i];
            continue;
        }
        if(t[i] > t[i-1]){
            M[i]=t[i]; m[i]=t[i];
        }else{
            M[i]=t[i]; m[i]=1;
        }
    }
    rep(i, n) {
        if(i==0){
            chmin(M[n-1-i], a[n-1-i]); chmax(m[n-1-i], a[n-1-i]);
            continue;
        }
        if(a[n-1-i] > a[n-i]){
            chmin(M[n-1-i], a[n-1-i]); chmax(m[n-1-i], a[n-1-i]);
        }else{
            chmin(M[n-1-i], a[n-1-i]); chmax(m[n-1-i], 1ll);
        }
    }
    ll res=1;
    rep(i,n){
        if(M[i]<m[i]){
            res=0;
            break;
        }
        res *= (M[i]-m[i]+1)%mod;
        res %= mod;
    }
    cout<<res<<endl;
    return 0;
}