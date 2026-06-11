#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int ans = 100100100;
    rep(i, s.size()) {
        int x = 0;
        int cnt = 0;
        rep(j, i) {
            if (s[j] != s[i]) ++cnt;
            else {
                x = max(x, cnt);
                cnt = 0;
            }
        }
        x = max(cnt, x);
        int y = s.size() - i - 1;
        ans = min(ans, max(x, y));
    }
    cout << ans << endl;
    return 0;
}
