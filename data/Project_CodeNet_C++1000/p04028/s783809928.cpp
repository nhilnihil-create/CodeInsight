#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll const mod = 1e9+7;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    string s;
    cin >> n >> s;
    int m = s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    dp[0][0] = 1;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            dp[i+1][j+1] += dp[i][j];
            if (j) (dp[i+1][j-1] += dp[i][j]*2) %= mod;
            else dp[i+1][0] += dp[i][0];
        }
    }
    cout << dp[n][m] << endl;
    // for (int i = 0;i < n+1;++i) p_ary(dp[i],0,n+1,j);
    return 0;
}