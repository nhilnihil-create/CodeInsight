#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, k, a;
    cin >> n >> k;
    vector<ll> num;
    map<ll, ll> d;
    rep1(i, k){
        cin >> a;
        d[a]++;
    }
    for (ll i=n; i<n*10+1; i++){
        ll num = i;
        bool judge = true;
        while (num>0){
            ll res = num % 10;
            if (d[res]>0) judge = false; 
            num /= 10;
        }
        if (judge){
            cout << i << endl;
            return 0;
        }
    }
    //priantf("%.12f", ans);
}