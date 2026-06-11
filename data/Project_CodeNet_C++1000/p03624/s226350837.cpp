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
bool d[26];
int main() {
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        int o = s[i] - 'a';
        d[o] = true;
    }
    for (int i = 0; i < 26; ++i) {
        if (!d[i]) {
            cout << char('a' + i) << endl;
            exit(0);
        }
    }
    cout << "None" << endl;
    return 0;
}
