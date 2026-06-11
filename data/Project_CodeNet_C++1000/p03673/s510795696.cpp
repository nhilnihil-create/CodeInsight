#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using ll = long long;
#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    // bool isRev = false;
    vector<int> frnt;
    vector<int> back;
    rep(i, 0, n) {
        int val;
        cin >> val;
        if (i % 2 == 0) {
            frnt.push_back(val);
        } else {
            back.push_back(val);
        }
    }

    if (n % 2 != 0) {
        reverse(frnt.begin(), frnt.end());
        for (int val : frnt) {
            printf("%d ", val);
        }
        rep(i, 0, back.size()) {
            printf("%d", back[i]);
            if (i != back.size() - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    } else {
        reverse(back.begin(), back.end());
        for (int val : back) {
            printf("%d ", val);
        }
        rep(i, 0, frnt.size()) {
            printf("%d", frnt[i]);
            if (i != frnt.size() - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}
