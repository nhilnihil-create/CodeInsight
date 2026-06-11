#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    //min_time[i][j] i色のj回以下の回転数で最小のa
    vector<vector<long long>> min_time(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        long long m = 1ll << 60;
        for (int j = 0; j < n; j++) {
            int r = (i - j + n) % n;
            m = min(m, a.at(r));
            min_time.at(i).at(j) = m;
        }
    }

    long long ans = 1ll << 60;
    for (int r = 0; r < n; r++) {
        long long sum = r * x;
        for (int i = 0; i < n; i++) {
            sum += min_time.at(i).at(r);
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;
}