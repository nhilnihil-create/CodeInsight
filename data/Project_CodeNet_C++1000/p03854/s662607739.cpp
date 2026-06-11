#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<string> strs = {"maerd", "remaerd", "esare", "resare"};
    reverse(all(s));
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        string ss = "";
        bool judge = 0;
        int cnt = 0;
        while (i < s.size() && cnt <= 7) {
            ss += s[i];
            cnt++;
            i++;
            if (cnt == 5) {
                if (ss == strs[0] || ss == strs[2]) {
                    judge = 1;
                    break;
                }
            }
            if (cnt == 6) {
                if (ss == strs[3]) {
                    judge = 1;
                    break;
                }
            }
            if (cnt == 7) {
                if (ss == strs[1]) {
                    judge = 1;
                    break;
                }
            }
        }
        i--;
        if (!judge) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}