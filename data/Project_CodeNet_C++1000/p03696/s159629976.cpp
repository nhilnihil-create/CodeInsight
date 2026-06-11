#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, Cnt, m;
string s;
int main() {
    cin >> n >> s;
    string ans;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == ')') {
            ++Cnt;
        } else {
            --Cnt;
        }
        if (Cnt < 0) {
            m -= Cnt;
            Cnt = 0;
        }
    }
    for (int i = 0; i < Cnt; ++i) {
        ans.push_back('(');
    }
    ans += s;
    for (int i = 0; i < m; ++i) {
        ans.push_back(')');
    }
    cout << ans << endl;
    return 0;
}
