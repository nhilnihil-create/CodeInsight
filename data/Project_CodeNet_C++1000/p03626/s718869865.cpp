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

const int mod = 1e9 + 7;
int n;
string s1, s2;
ll res;

int main() {
    cin >> n >> s1 >> s2;
    res = 1;
    int i = 0;
    int p = 0;
    while (i < n) {
        if (s1[i] == s2[i]) { // v
            ++i;
            if (p == 0) {
                res = 3;
            } else if (p == 1) { // v
                res = res * 2 % mod;
            } else if (p == 2) { // h
            }
            p = 1;
        } else { // h
            i += 2;
            if (p == 0) {
                res = 6;
            } else if (p == 2) {
                res = res * 3 % mod;
            } else if (p == 1) {
                res = res * 2 % mod;
            }
            p = 2;
        }
    }
    cout << res << endl;
    return 0;
}
