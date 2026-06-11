#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    string s;
    cin >> s;
    int ans = INF;
    for(char t = 'a'; t <= 'z'; t++) {
        int tot = 0, cnt = 0;
        rep(i, s.size()) {
            if(s[i] == t) {
                tot = max(tot, cnt);
                cnt = 0;
            } else if(i == s.size() - 1) {
                tot = max(tot, cnt + 1);
            } else {
                cnt++;
            }
        }
        ans = min(ans, tot);
    }
    cout << ans << endl;

    return 0;
}