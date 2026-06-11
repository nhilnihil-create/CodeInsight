#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
string S;
ll dp[5010][5010];
ll mod = 1000000007;

ll pow_mod(ll a,ll b)
{
    if(b == 0)return 1;
    ll res = pow_mod(a * a % mod,b / 2);
    if(b & 1)res = res * a % mod;
    return res;
}

int main()
{
   scanf("%d",&N);
   cin >> S;

   dp[0][0] = 1;

   for(int i = 0; i <= N; i++)
   {
       for(int j = 0; j <= N; j++)
       {
           dp[i][j] %= mod;
           dp[i + 1][max(j - 1,0)] += dp[i][j];
           dp[i + 1][j + 1] += 2 * dp[i][j];
       }
   }

   ll R = 1;
   for(int i = 0; i < S.size(); i++)R = R * 2 % mod;
   printf("%lld\n",dp[N][S.size()] * pow_mod(R,mod - 2) % mod);
   return 0;
}
