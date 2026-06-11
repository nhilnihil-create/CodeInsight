#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
  
int main() {
    ll h, w;
    cin >> h >> w;

    map<ll, ll> mp;
    rep(i, h) {
        rep(j, w) {
            char c;
            cin >> c;
            mp[c]++;
        }
    }

    ll cntOdd = 0;  // 奇数個ある英字の種類数
    for(auto p : mp) {
        if(p.second%2 == 1) {
            cntOdd++;
        }
    }

    bool ok = true;
    if(h%2 == 1 && w%2 == 1) {
        if(cntOdd != 1) {
            ok = false;
        }
    }
    else {
        if(cntOdd != 0) {
            ok = false;
        }
    }
    
    ll cnt4 = 0;  // 作れる4個組の個数
    for(auto p : mp) {
        cnt4 += p.second/4;
    }
    if(cnt4 < (h/2)*(w/2)) {
        ok = false;
    }

    if(ok) {
        out("Yes");
    }
    else {
        out("No");
    }

    re0;
}