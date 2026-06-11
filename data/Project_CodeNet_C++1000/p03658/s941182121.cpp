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

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> l(n);
    for(int in=0;in<n;in++) {
        cin >> l.at(in);
    }

    sort(l.begin(), l.end(), greater<int>());

    int ans = 0;
    for(int ik=0;ik<k;ik++) {
        ans += l.at(ik);
    }
    cout << ans << endl;
    return 0;
}
