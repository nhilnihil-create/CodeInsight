#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

//mt19937 rng(333);
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 107;
const int MX = 107;

int dp[N][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(a.rbegin(), a.rend());
    map <int, int> who;
    int lst = -1;
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || a[i] > a[i + 1]) {
            who[a[i] - 1 - i] = 1;
            for (int j = i - 1; j > lst; j--) {
                who[a[i] - 1 - j] = 3 - who[a[i] - 1 - (j + 1)];
            }
            lst = i;
        }
    }
    map <int, int> has;
    vector <pair <int, int> > cut;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] > a[i + 1]) {
            cut.push_back({a[i + 1] - 1, i});
            has[a[i + 1] - 1 - i] = 1;
        }
    }
    auto f = [&] (int x, int y) {
        int kek = a[y] - 1;
        int diff = kek - x;
        diff %= 2;
        return diff;
    };
    cut.push_back({0, n - 1});
    if (who[0]) {
        who[0]--;
        cout << (who[0] ? "First\n" : "Second\n");
    } else {
        if (has[0]) {
            bool good = false;
            for (auto to : cut) {
                if (to.first - to.second == 0) {
                    if (!f(to.first + 1, to.second) || who[to.first - to.second - 1] == 1) {
                        good = true;
                    }
                }
            }
            cout << (good ? "First\n" : "Second\n");
            return 0;
        }
        for (auto to : cut) {
            int x = to.second;
            if (x >= to.first && x <= a[to.second]) {
                cout << (f(x, x) ? "First\n" : "Second\n");
                return 0;
            }
        }
    }
    return 0;
}
