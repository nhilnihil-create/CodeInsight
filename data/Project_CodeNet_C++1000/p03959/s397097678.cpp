/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 62;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
int main(void){
    ll n;
    cin >> n;
    vector<ll> t(n), a(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> a[i];

    vector<ll> pat(n, 0);
    ll maxt = 0;
    vector<ll> decided(n, -1);
    rep(i, n){
        if(t[i] > maxt){
            pat[i] = 1;
            maxt = t[i];
            decided[i] = t[i];
        } else {
            pat[i] = t[i];
        }
    }
    ll maxa = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] > maxa){
            pat[i] = 1;
            maxa = a[i];
            if(decided[i] != -1 && a[i] != decided[i]){
                cout << 0 << endl;
                return 0;
            }
        } else {
            pat[i] = min(pat[i], a[i]);
            if(decided[i] != -1 && a[i] < decided[i]){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    ll ans = 1;
    rep(i,n){
        //cout << i << " " << pat[i] << endl;
        ans *= pat[i];
        ans %= MOD;
    }

    if(maxa != maxt){
        cout << 0 << endl;
        return 0;
    }
    cout << ans << endl;
}