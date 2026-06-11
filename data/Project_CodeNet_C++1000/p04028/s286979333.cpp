#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
string S;
ll dp[5010][5010] = {0};// 操作回数 文字の長さ
ll mod = 1000000007;

int main()
{
   scanf("%d",&N);
   cin >> S;

   dp[0][0] = 1;

   for(int i = 1; i <= N; i++)
   {
       for(int j = 0; j <= N; j++)
       {
           dp[i][j] = dp[i - 1][max(0,j - 1)] + 2 * dp[i - 1][j + 1];
           dp[i][j] %= mod;
       }
   }

   printf("%lld\n",dp[N][S.size()]);
   return 0;
}
