#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

llint frac(llint n, llint m) {
    llint ans = 1LL;
    for(int in=n;in>=1;in--) {
        ans *= in;
        ans %= MOD;
    }
    for(int im=m;im>=1;im--) {
        ans *= im;
        ans %= MOD;
    }
    if(n==m) {
        ans *= 2;
        ans %= MOD;
    }
    return ans;
}

int main(void) {
    llint n, m, ans;
    cin >> n >> m;

    if(abs(n-m)>=2)  {
        cout << 0 << endl;
        return 0;
    }
    else {
        ans = frac(n, m);
    }
    cout << ans << endl;
    return 0;
}
