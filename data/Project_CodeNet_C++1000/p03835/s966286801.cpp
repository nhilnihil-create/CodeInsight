#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, s;
    long long ans = 0;
    cin >> k >> s;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            if(0 <= s - i - j && s - i - j <= k) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}