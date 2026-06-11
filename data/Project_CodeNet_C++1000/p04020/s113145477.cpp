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
    ll N;
    cin >> N;
    vector<ll> A(N), remain(N);
    REP(i, N) cin >> A[i];

    ll ans = 0;
    REP(i, N) {
        ll r = 0;
        if(i > 0) r = remain[i-1];
        ll tmp = (r + A[i]) / 2;
        ans += tmp;
        // cerr << "i = " << i << " tmp = " << tmp << endl;
        // if(i > 0) remain[i-1] = 0;
        if(tmp > 0)
            remain[i] = max(0ll, (r + A[i] - 2 * tmp));
    }

    // cerr << "debug" << endl;
    // REP(i, N) cerr << remain[i] << endl;
    // cerr << "end of debug" << endl;

    cout << ans << endl;

    return 0;
}
