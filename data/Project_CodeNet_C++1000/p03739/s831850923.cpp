#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, total, total2, cnt, cnt2;
    total2 = total = cnt2 = cnt = 0;
    cin >> n;
    for (int i=0;i<n;++i) {
        long long ai;
        cin >> ai;
        total2 += ai;
        total += ai;
        if (i % 2 == 0) {
            if (total <= 0) {
                cnt += -total + 1;
                total = 1;
            }
            if (total2 >= 0) {
                cnt2 += total2 + 1;
                total2 = -1;
            }
        } else {
            if (total >= 0) {
                cnt += total + 1;
                total = -1;
            }
            if (total2 <= 0) {
                cnt2 += -total2 + 1;
                total2 = 1;
            }
        }
    }
    cout << ((cnt < cnt2) ? cnt : cnt2);
}

int main() {

    solve();
    return 0;
}
