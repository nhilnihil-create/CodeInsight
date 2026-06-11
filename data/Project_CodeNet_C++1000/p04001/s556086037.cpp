#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    string s;
    cin >> s;
    int m = s.size() - 1;
    int64_t ans = 0;
    for (int bit = 0; bit < (1 << m); bit++){
        int64_t tmp = s.at(0) - '0';
        for (int i = 0; i < m; i++){
            if (bit & (1 << i)){
                ans += tmp;
                tmp = 0;
            }
            tmp = tmp * 10 + (s.at(i + 1) - '0');
        }
        ans += tmp;
    }
    cout << ans << endl;
}
