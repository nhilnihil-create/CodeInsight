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
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
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
    ll n;
    cin >> n;

    vl a(n);
    ll minA = n, maxA = 0;
    rep(i, n) {
        cin >> a[i];
        chmin(minA, a[i]);
        chmax(maxA, a[i]);
    }

    if(maxA - minA >= 2) {
        out("No");
        re0;
    }

    if(maxA - minA == 0) {
        if(maxA == n-1) {
            out("Yes");
        }
        else if(2*maxA <= n) {
            out("Yes");
        }
        else {
            out("No");
        }
    }
    else if(maxA - minA == 1) {
        ll x = 0, y = 0;
        rep(i, n) {
            if(a[i] == minA) {
                x++;
            }
            else if(a[i] == maxA) {
                y++;
            }
        }
        if(x < maxA && 2*(maxA - x) <= y) {
            out("Yes");
        }
        else {
            out("No");
        }
    }
    
    re0;
}