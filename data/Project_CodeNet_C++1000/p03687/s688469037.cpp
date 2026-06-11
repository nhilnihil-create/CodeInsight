#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int dfs(string s, char c, int cost){
    int n = s.size();
    bool flag = true;
    rep(i, n) flag &= (s[i]==c);
    if (flag) return cost;

    string t;
    rep(i, n-1){
        if (s[i] == c || s[i+1] == c) t += c;
        else t += s[i];
    }
    return dfs(t, c, cost+1);
}


int main(){
    string s;
    cin >> s;
    int ans = 100;

    rep(i, 26){
        ans = min(ans, dfs(s, i + 'a', 0));
    }

    cout << ans << endl;


    return 0;
}
