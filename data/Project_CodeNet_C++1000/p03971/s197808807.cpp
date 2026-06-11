#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    vector<bool> pass(n, false);
    int cnt_all = 0, rank_foreign = 1;
    rep(i, n) {
        if (s[i] == 'a') {
            if (cnt_all < a+b) {
                cnt_all++;
                pass[i] = true;
            }
        } else if (s[i] == 'b') {
            if (cnt_all < a+b && rank_foreign <= b) {
                cnt_all++;
                rank_foreign++;
                pass[i] = true;
            }
        }else continue;
    }
    rep(i, n) {
        if (pass[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}