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
int main() {
    cin >> s;
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'p') {
            ++cnt;
        }
    }
    int max_cnt = n / 2;
    cout << max_cnt - cnt << endl;
    return 0;
}
