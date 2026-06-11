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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> c(n, vector<int>(n, 0));
    int a, b;
    for(int im=0;im<m;im++) {
        cin >> a >> b; a--; b--;
        c.at(a).at(b)++;
        c.at(b).at(a)++;
    }

    int ans;
    for(int in=0;in<n;in++) {
        ans = 0;
        for(int jn=0;jn<n;jn++) {
            ans += c.at(in).at(jn);
        }
        cout << ans << endl;
    }
    return 0;
}
