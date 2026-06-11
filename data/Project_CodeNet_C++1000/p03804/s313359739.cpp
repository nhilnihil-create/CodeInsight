#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll mod = 1e9+7;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> as(n), bs(m);
    rep(i, n) cin >> as[i];
    rep(i, m) cin >> bs[i];
    rep(i, n-m+1) {
        rep(j, n-m+1) {
            bool check = true;
            rep(k, m) {
                if (as[i+k].compare(j, m, bs[k]) != 0) {
                    check = false; 
                    break;
                }
            }
            if (check) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    } 
    cout << "No" << endl;
    return 0;
}