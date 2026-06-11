#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = long long int;
using uli = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    const int MAX_SEAT = 1000000;
    int n;
    cin >> n;
    bool seats[MAX_SEAT]{false};
    while (n--) {
        int r, l;
        cin >> r >> l;
        for (int i = r; i <= l; i++) {
            seats[i - 1] = true;
        }
    }

    int cnt = 0;
    rep(i, MAX_SEAT) if (seats[i] == true) cnt++;
    cout << cnt << endl;
}