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

string s;
int n;

inline bool check(int x) {
    if ((n - x) & 1) return false;
    int m = (n - x) / 2;
    for (int i = 0; i < m; ++i) {
        if (s[i] != s[m + i]) return false;
    }
    return true;
}

int main() {
    cin >> s;
    n = s.length();
    for (int i = 1; i < n; ++i) {
        if (check(i)) {
            cout << n - i << endl;
            exit(0);
        }
    }
    return 0;
}
