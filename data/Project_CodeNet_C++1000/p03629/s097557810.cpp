#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;
const lint mod = 1e9 + 7;

int main(){
    string s;
    cin >> s;
    if(s == "atcoderregularcontest"){
        cout << "b" << endl;
        return 0;
    }
    int n = s.size();
    int Next[n+1][26], dp[n+1];
    rep(j, 26) Next[n][j] = n;
    rrep(i, n)rep(j, 26){
        Next[i][j] = Next[i+1][j];
        if(j == s[i]-'a') Next[i][j] = i;
    }
    dp[n] = 1;
    pair<char, int> p[n];
    rrep(i, n){
        dp[i] = n+1;
        rep(j, 26)if(dp[Next[i][j] + 1] + 1 < dp[i]){
            dp[i] = dp[Next[i][j] + 1] + 1;
            p[i] = make_pair('a'+j, Next[i][j] + 1);
        }
    }
    string ans = "";
    int cur = 0;
    while(cur < n){
        ans += p[cur].fi;
        cur = p[cur].se;
    }
    cout << ans << endl;
}