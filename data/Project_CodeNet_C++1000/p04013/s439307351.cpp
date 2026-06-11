#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

ll dp[55][55][2505];

int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int N,A;
cin >> N >> A;
vl x(N);
rep(i,N) cin >> x[i];

dp[0][0][0] = 1;
rep(i,N)rep(j,N)rep(k,2500){
    dp[i+1][j][k] += dp[i][j][k];
    dp[i+1][j+1][k+x[i]] += dp[i][j][k];
}
ll ans = 0;
rrep(i, N) {
    ans += dp[N][i][i*A];
}
cout << ans << endl;
return 0;
}