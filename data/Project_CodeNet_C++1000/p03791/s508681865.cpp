#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 2e5;
int a[maxN];

int main(void) {

    int n;
    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cur = 1;
    vector <int> cnt;
    int prev = -1;
    int c = 0;
    for (int i = 0; i < n; i++) {
        a[i] = min(cur, a[i]);
        cur = a[i] + 2;
        if (a[i] - 1 == prev) {
            c++;
        } else {
            if (c) {
                cnt.push_back(c);
            }
            c = 1;
        }
        prev = a[i];
    }
    cnt.push_back(c);
    long long ans = 1;
    int mod = 1e9 + 7;
    int sum = 0;
    int nxt = 0;
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i] == 1) {
            sum += cnt[i];
            continue;
        } else {
            if (nxt) {
                cnt[i] -= nxt;
                sum++;
                nxt = 0;
            }
            while (cnt[i] > 2) {
                ans *= sum + 2;
                ans %= mod;
                sum++;
                cnt[i] -= 2;
            }
            if (cnt[i] == 2) {
                ans *= sum + 2;
                ans %= mod;
                nxt = 1;
            }
            sum++;
        }
    }

    while (sum) {
        ans *= sum;
        ans %= mod;
        sum--;
    }

    cout << ans << endl;



    return 0;
}
