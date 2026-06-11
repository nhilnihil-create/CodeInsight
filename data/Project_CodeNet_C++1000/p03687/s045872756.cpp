#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string s; cin >> s;
    int n = s.size();
    int ans = n;
    rep(i, 26){
        char a = 'a' + i;
        int ma = 0;
        int now = 0;
        rep(j, n){
            if(s[j] != a){
                now++;
            } else {
                ma = max(ma, now);
                now = 0;
            }
            if(j == n-1){
                ma = max(ma, now);
            }
        }
        ans = min(ans, ma);
    }

    cout << ans << endl;

    return 0;
}