#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());

    vector<string> a = {
        "dream",
        "dreamer",
        "erase",
        "eraser",
    };
    rep(i, a.size()) {
        reverse(a[i].begin(), a[i].end());
    }

    int i = 0;
    bool allok = true;
    while (i < S.size()) {
        int ans_j = -1;
        rep(j, a.size()) {
            bool ok = true;

            rep(k, a[j].size()) {
                if (S[i + k] != a[j][k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans_j = j;
                break;
            }
        }
        if (ans_j == -1) {
            allok = false;
            break;
        }
        i += a[ans_j].size();
    }

    if (allok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}