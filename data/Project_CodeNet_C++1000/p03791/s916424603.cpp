#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
    }
    ll cnt = 0;
    ll res = 1;
    rep(i,n){
        cnt++;
        if(i>0&&a[i]<2*cnt-1){
            res *= cnt;
            res %= MOD;
            cnt--;
        }
    }
    DEBUG{
        cout << "cnt: "<< cnt << endl;
        cout << "res: "<< res << endl;
    }
    while(cnt>0){
        res *= cnt;
        res %= MOD;
        cnt--;
    }
    cout << res << endl;
    return 0;
}
