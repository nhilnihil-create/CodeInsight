#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n,0), b(n,0);
    rep1(i, n) cin >> a[i];
    ll res = n-1;
    bool change = false;
    rep1(i,n){
        if (!change){
            b[i] = a[res];
            res -= 2;
            if (res==-2){
                change = true;
                res = 1;
                continue;
            }
            if (res==-1){
                change = true;
                res = 0;
                continue;
            }
        }
        if (change){
            b[i] = a[res];
            res += 2;
        }
    }
    rep1(i, n){
        if (i==n-1) cout << b[i] << endl;
        else cout << b[i] << " ";
    }
}