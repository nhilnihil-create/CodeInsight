#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    string s;
    cin >> s;

    char dx[4] = {'S', 'W', 'S', 'W'};
    char dy[4] = {'S', 'W', 'W', 'S'};

    rep(i, 4) {
        vector<char> ans;
        ans.push_back(dx[i]);
        ans.push_back(dy[i]);

        for (int i = 1; i < N - 1; i++) {
            if ((s[i] == 'o' && ans[i] == 'S') ||
                (s[i] == 'x' && ans[i] == 'W')) {
                if (ans[i - 1] == 'S')
                    ans.push_back('S');
                else
                    ans.push_back('W');
            } else if ((s[i] == 'x' && ans[i] == 'S') ||
                       (s[i] == 'o' && ans[i] == 'W')) {
                if (ans[i - 1] == 'S')
                    ans.push_back('W');
                else
                    ans.push_back('S');
            }
        }

        bool judge = 1;

        int check[2] = {N - 1, 0};

        rep(j, 2) {
            int tar = check[j];
            int prev = (j == 1) ? N - 1 : tar - 1;
            int next = (j == 0) ? 0 : tar + 1;
            if ((s[tar] == 'o' && ans[tar] == 'S') ||
                (s[tar] == 'x' && ans[tar] == 'W')) {
                if (ans[prev] != ans[next])
                    judge = 0;

            } else if ((s[tar] == 'x' && ans[tar] == 'S') ||
                       (s[tar] == 'o' && ans[tar] == 'W')) {
                if (ans[prev] == ans[next])
                    judge = 0;
            }
        }

        if (judge) {
            rep(k, N) { cout << ans[k]; }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}