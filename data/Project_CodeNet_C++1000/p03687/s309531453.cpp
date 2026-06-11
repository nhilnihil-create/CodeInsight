#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    string ss;
    cin >> ss;

    bool perfect = true;
    rep(i, ss.size() - 1) {
        if (ss[i] != ss[i + 1])
            perfect = false;
    }

    if (perfect) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1e5;
    for (char i = 'a'; i <= 'z'; i++) {
        string s = ss;
        int cnt = 0;
        while (true) {
            bool judge = 0;
            string news = "";
            for (int j = 0; j < s.size() - 1; j++) {
                if (s[j] == i || s[j + 1] == i) {
                    news += i;
                    judge = 1;
                } else {
                    news += s[j];
                }
            }

            s = news;
            if (!judge)
                break;
            cnt++;

            bool flag = true;
            rep(k, s.size()) {
                if (s[k] != i) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = min(ans, cnt);
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}