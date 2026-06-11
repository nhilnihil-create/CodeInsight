#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string a, b,ans;
    cin >> a >> b;
    if (a.size() != b.size()) {
        if (a.size() > b.size())ans = "GREATER";
        else ans = "LESS";
    }
    else {
        if (a == b)ans = "EQUAL";
        else {
            rep(i, a.size()) {
                if (a[i] != b[i]) {
                    if (a[i] > b[i])ans = "GREATER";
                    else ans = "LESS";
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}