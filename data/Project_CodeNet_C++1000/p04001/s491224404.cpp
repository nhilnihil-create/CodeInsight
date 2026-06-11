#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    string S; cin >> S;
    int l = S.size();

    ll res = 0;
    for (int i = 0; i < 1<<(l - 1); i++) {
        vector<char> x;
        for (int j = 0; j < (l - 1); j++) {
            x.push_back(S.at(j));
            if (i & 1<<j) {
                x.push_back('+');
            }
        }
        x.push_back(S.at(l - 1));

        vl y;
        string tmp;
        rep(i, x.size()) {
            if (x[i] == '+') {
                y.push_back(stol(tmp));
                tmp = "";
            } else {
                tmp += x[i];
            }
        }
        if (tmp != "") y.push_back(stol(tmp));

        rep(i, y.size()) res += y[i];
    }
    cout << res << endl;
}
