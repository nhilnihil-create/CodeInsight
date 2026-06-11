#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0, ans1 = 0, ans2 = 0, acum = 0;
    REP(i, n) cin >> a[i];

    // a[0] > 0
    acum = a[0];
    if(a[0] <= 0) {
        acum = 1;
        ans1 += 1 - a[0];
    }
    FOR(i, 1, n-1) {
        if(i%2==0) {
            if(acum + a[i] > 0) {
                acum += a[i];
            } else {
                ans1 += 1 - (acum + a[i]);
                acum = 1;
            }
        } else {
            if(acum + a[i] < 0) {
                acum += a[i];
            } else {
                ans1 += 1 + (acum + a[i]);
                acum = -1;
            }
        }
        // cout << "i = " << i << " acum = " << acum << " ans1 = " << ans1 << endl;
    }

    // a[0] < 0
    acum = a[0];
    if(a[0] >= 0) {
        acum = -1;
        ans2 += a[0] + 1;
    }
    FOR(i, 1, n-1) {
        if(i%2==1) {
            if(acum + a[i] > 0) {
                acum += a[i];
            } else {
                ans2 += 1 - (acum + a[i]);
                acum = 1;
            }
        } else {
            if(acum + a[i] < 0) {
                acum += a[i];
            } else {
                ans2 += 1 + (acum + a[i]);
                acum = -1;
            }
        }

        // cout << "i = " << i << " acum = " << acum << " ans2 = " << ans2 << endl;
    }

    cout << min(ans1, ans2) << endl;

    return 0;
}