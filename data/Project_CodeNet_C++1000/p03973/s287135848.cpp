#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
 
#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")
 
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define endl '\n';
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <class T> inline T gcd(T a, T b) { while (b) { a %= b; swap(a, b); } return a; }
template <class T> inline T lcm(T a, T b) { return a * b / gcd(a, b); }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
    #define eprintf(...) 42
#endif

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const ll MOD = (ll)1e9 + 7, INF = (ll)1e18;;
ll add(ll x, ll y) {
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll sub(ll x, ll y) {
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
ll mul(ll x, ll y) {
    return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
    if (p == 0) return 1;
    if (p & 1) return mul(x, bin_pow(x, p - 1));
    return bin_pow(mul(x, x), p / 2);
}

const int N = 100100;
ll a[N];
ll n, k = 2, ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    startTime = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    ans = a[0] - 1;
    for (int i = 1; i < n; ++i) {
        ll t = (a[i] - 1) / k;
        if (t == 0)
            k = max(k, a[i] + 1);
        ans += t;
    }
    cout << ans << endl;
    
    return 0;
}
