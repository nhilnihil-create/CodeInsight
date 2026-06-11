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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    REP(i, N) cin >> a[i];

    ll ans = INF;
    for(int bit = 0; bit < (1<<N); ++bit) {
        if(__builtin_popcount(bit) != K) continue;
        ll cur_highest = 0;
        ll tmp = 0;
        for(int i=0; i<N; ++i) {
            if((bit & (1<<i)) && i == 0) {
                cur_highest = a[i];
            } else if((bit & (1<<i))) {
                tmp += max(0ll, cur_highest + 1 - a[i]);
                if(cur_highest + 1 >= a[i])
                    cur_highest = cur_highest + 1;
                else
                    cur_highest = a[i];
            } else {
                cur_highest = max(cur_highest, a[i]);
            }
        }
        ans = min(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}