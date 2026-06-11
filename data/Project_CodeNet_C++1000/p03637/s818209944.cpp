#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

int main() {
    long long n;
    cin >> n;
    vector<int> as(n);
    vector<int> bs(n);
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        bs[i] = as[i];
        if (as[i] % 2 == 0) {
            // cout << as[i] << endl;
            int g = 0;
            while (as[i] % 2 == 0 && g < 2) {
                as[i] = as[i] / 2;
                sum2++;
                g++;
            }
        }
    }
    int sum4 = 0;
    if (n % 2 == 1) {
        REP(i, n) {
            if (bs[i] % 4 == 0) {
                sum4++;
            }
        }
        // cout << sum4;
        if (sum4 == 0 && sum2 != n) {
            no();
        }
    }
    // cout << sum2 << " " << 2 * (n / 2) << endl;
    if (sum2 >= 2 * (n / 2)) {
        yes();
    } else {
        no();
    }
}