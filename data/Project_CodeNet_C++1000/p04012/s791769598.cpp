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
int cnt[26];
int main() {
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] & 1) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
    return 0;
}
