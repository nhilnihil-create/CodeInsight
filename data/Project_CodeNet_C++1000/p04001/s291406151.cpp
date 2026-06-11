#include <bits/stdc++.h>
using namespace std;

int main() {
    long long s, ss, div, ans = 0;
    cin >> s;
    int num = log10(s), ii;
    for (int bit = 0; bit < (1 << num + 1); bit += 2) {
        ss = s;
        ii = 0;
        for (int i = 1; i <= num; i++) {
            if (bit & (1 << i)) {
                div = pow(10, i - ii);
                ans += ss % div;
                ss /= div;
                ii = i;
            }
        }
        ans += ss;
    }
    cout << ans << endl;
}