#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
#define REP(i, n) for (int64_t i = 0; i < (int64_t)n; i++)
#define REP_FOR(i, a, b) for (int64_t i = (int64_t)a; i < (int64_t)b; i++)
#define REP_REV(i, a, b) for (int64_t i = (int64_t)a; i > (int64_t)b; i--)
#define FORALL(v) (v).begin(), (v).end()
#define mp(a, b) make_pair(a, b)
#define eb(x) emplace_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int64_t, int64_t> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int64_t> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int64_t infi = 1147483600;
const ll infl = 4e18 + 5;
const char EOL = '\n';
//cout << fixed << setprecision(17) << res << endl;
const ll MOD = 998244353;

int main() {
    int N;
    cin >> N;
    
    ll place[N + 1];
    // place[i]...値iのaにおけるindex
    
    for (int i = 1; i <= N; ++i) {
        ll a;
        cin >> a;
        place[a] = i;
        // 保持するのはindexなので、ここが普通と逆なことに注意
    }

    ll ans = 0;
    set<ll> used = {0, N + 1};
    // すでに見た要素のindexを保持する
    
    for (int i = 1; i <= N; ++i) {
        ll r, l;
        
        auto itr = used.lower_bound(place[i]);
        r = *itr;
        // lower_boundで右端を調べる(upper_boundでもいい)
        l = *(--itr);
        // その1個手前が左端
        
        ans += i * (place[i] - l) * (r - place[i]);
        used.insert(place[i]);
    }

    cout << ans << endl;
    return 0;
}
