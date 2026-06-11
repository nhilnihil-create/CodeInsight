#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

int div_time(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n % 2 == 0) {
            cnt++;
            n /= 2;
        } else {
            break;
        }
    }
    return cnt;
}

int main() {
    fastIO;

    int n;
    cin >> n;

    int maxv = 1, max_cnt = 0;
    for (int i = n; i >= 0; --i) {
        int div_cnt = div_time(i);
        if (max_cnt < div_cnt) {
            maxv = i;
            max_cnt = div_cnt;
        }
    }
    cout << maxv << endl;
}