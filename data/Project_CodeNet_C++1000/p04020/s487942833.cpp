# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <chrono>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <cctype>
# include <unordered_map>
# include <unordered_set>
//#include <bits/stdc++.h>
 
#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i, n) for (int i = 0; i < (n); i++)
#define forx(i,x,n) for (int i = x; i < (n); i++)
#define form(i, n) for (int i = n-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define pf push_front
#define mp make_pair
#define ll long long
#define ld long double
#define ull unsigned ll
#define srt(a) sort(a.begin(), a.end());
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pld pair<ld,ld>
#define ar array
#define endl '\n';
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <class T> inline T gcd(T a, T b) { while (b) { a %= b; swap(a, b); } return a; }
template <class T> inline T lcm(T a, T b) { return a * b / gcd(a, b); }
 
const ll MAXN = 32005, K = 200043, M = 1000043, INF = 1e18 + 7;
// the good way to get PI number
const ld PI = acos(-1.0);
ll MOD = 1e9 + 7;

template <class T> T sqr(T a) {
    return a * a;
}

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll sum(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a, ll b) {
    return sum(a, MOD - b);
}

ll bin_pow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    
    vl a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    ll ans = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (a[i] == 0) {
            ans += sum / 2;
            sum = 0;
        }
    }
    ans += sum / 2;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
//    cin >> t;
    
    while (t --> 0)
        solve();
    return 0;
}
