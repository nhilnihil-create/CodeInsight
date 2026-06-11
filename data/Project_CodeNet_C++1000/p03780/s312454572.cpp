// {{{
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long int i32;
typedef unsigned long int u32;
typedef long long int i64;
typedef unsigned long long int  u64;
typedef pair<i32, i32> PII;
#define IN(x) cin >> x;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define ZERO(a) memset(a, 0, sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j-1, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define MP make_pair
#define PB push_back
#define PF push_front
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define DEBUG(x) cout << #x << ": " << x << endl;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
// }}}

const u32 MAX_N = 5000;
const u32 MAX_K = 5000;
u32 N, K;
vector<u32> a;

bool check(i32 m) {
    // printf("m: %d\n", m);
    array<bool, MAX_K+1> dp;
    fill(all(dp), false);
    dp[0] = true;
    REP(i, N) {
        if(i == m) {
            continue;
        }
        RREP(j, K) {
            if(dp[j] && j + a[i] < K) {
                dp[j+a[i]] = dp[j+a[i]] || dp[j];
            }
        }
    }
    REP(j, K) {
        // printf("dp[%d]: %d, j+a[m]: %d\n", j, dp[j], j+a[m]);
        if(dp[j] && j + a[m] >= K) {
            return true;
        }
    }
    return false;

}

int main() {
    cin >> N >> K;
    a = vector<u32>(N);
    REP(i, N) {
        IN(a[i]);
    }
    sort(a.rbegin(), a.rend());
    i32 l = -1;
    i32 r = N;
    i32 m = (l + r + 1) / 2;
    while(r - l > 1) {
        if(check(m)) {
            l = m;
        } else {
            r = m;
        }
        m = (l + r + 1) / 2;
    }
    // printf("m: %d\n", m);
    cout << N - m << endl;
    return 0;
}
