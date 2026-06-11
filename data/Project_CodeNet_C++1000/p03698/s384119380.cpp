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

int a[26];
string s;
int main() {
    cin >> s;
    bool ok = true;
    for (int i = 0; i < s.length(); ++i) {
        if (++a[s[i] - 'a'] > 1) {
            ok = false;
        }
    }
    if (ok)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
