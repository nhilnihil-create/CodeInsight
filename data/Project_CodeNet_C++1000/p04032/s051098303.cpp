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

const int N = 1e5 + 5;
int n, m, k, ans;

string s;
int main() {
    cin >> s;
    int n = s.length();
    for (char c = 'a'; c <= 'z'; ++c) {
        int l = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                ++cnt;
            }
            while (cnt * 2 < i - l + 1 && l <= i) {
                if (s[l++] == c)
                    --cnt;
            }
            if (cnt * 2 > i - l + 1 && i - l + 1 >= 2) {
                cout << l + 1 << ' ' << i + 1 << endl;
                exit(0);
            }
        }
    }
    cout << -1 << ' ' << -1 << endl;
    return 0;
}
