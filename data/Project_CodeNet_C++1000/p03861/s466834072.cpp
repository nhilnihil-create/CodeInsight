#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

llint x;

llint solve(llint n) {
    if(n==-1) return 0;
    else return n/x+1;
}

int main(void) {
    llint a, b, ans1, ans2, ans;
    cin >> a >> b >> x;

    cout << solve(b)-solve(a-1) << endl;
    return 0;
}
