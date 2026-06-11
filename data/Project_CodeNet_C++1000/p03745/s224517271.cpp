#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vec a(n);
    rep(i, n) cin >> a[i];

    int res = 0;

    for (int i = 0; i < n; i++) {
        while (i+1 < n && a[i] == a[i+1]) i++;

        if (i+1 < n && a[i] < a[i+1]) {
            while (i+1 < n && a[i] <= a[i+1]) i++;
        }
        else if (i+1 < n && a[i] > a[i+1]) {
            while (i+1 < n && a[i] >= a[i+1]) i++;
        }

        res++;
    }

    cout << res << endl;
    return 0;
}