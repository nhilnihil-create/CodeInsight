#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
#define REP(i, n) for(int i = 0;i < n;i++)
const long long INF = 1LL << 60;

int MOD = 1000000007;



int main(){
    std::ios_base::sync_with_stdio(false);

    int n, t; cin >> n >> t;
    std::vector<ll> a(n); REP(i,n) cin >> a[i];
    std::vector<ll> m(n); m[0] = a[0];
    std::vector<ll> d(n);

    REP(i,n) if(i!=0) m[i] = min(a[i], m[i-1]);
    REP(i,n) d[i] = a[i]-m[i];

    int ans = 0; ll mi = -1;

    REP(i,n) mi = max(mi, d[i]);
    REP(i,n) if(d[i] == mi) ans++;

    cout << ans << endl;

    return 0;
}
