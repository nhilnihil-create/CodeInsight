#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i) 
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

constexpr static int MOD = 1000000000 + 7;
constexpr static int inf = INT_MAX / 2;
constexpr static llong INF = 1LL<<31;
constexpr static int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    string initial_two[] = {"SS", "SW", "WW", "WS"};
    rep(i, 4) {
        string zoo = initial_two[i];
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == 'o') {
                if (zoo[i] == 'S') zoo += zoo[i - 1];
                else zoo += (zoo[i - 1] == 'S' ? 'W' : 'S');
            } else { // x
                if (zoo[i] == 'S') zoo += (zoo[i - 1] == 'S' ? 'W' : 'S');
                else zoo += zoo[i - 1];
            }
        }
        // cout << zoo << endl;
        bool flag = true;
        string check = zoo[n - 1] + zoo + zoo[0];
        for (int i = 1; (i <= n) && flag; ++i) {
            if (check[i] == 'S' && s[i - 1] == 'o') {
                if (check[i - 1] != check[i + 1]) flag = false;
            }
            if (check[i] == 'S' && s[i - 1] == 'x') {
                if (check[i - 1] == check[i + 1]) flag = false;
            }
            if (check[i] == 'W' && s[i - 1] == 'o') {
                if (check[i - 1] == check[i + 1]) flag = false;
            }
            if (check[i] == 'W' && s[i - 1] == 'x') {
                if (check[i - 1]!= check[i + 1]) flag = false;
            }
        }
        if (flag) {
            cout << zoo << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}