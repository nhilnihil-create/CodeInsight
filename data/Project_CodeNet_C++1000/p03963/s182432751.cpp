#include <bits/stdc++.h>
using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define int long long
  #define endl "\n"
  #define all(v) v.begin(),v.end()
  #define double long double
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
  const int N = 200005;


int32_t main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS

    int n,k;
    cin >> n >> k;

    int dp[n+1][k+1];

    // dp[n][k] denotes the number of ways to color the first n colors
    // such that the last color is k
    // ans = summation of dp[n][all colors]

    for(int i = 1; i <= k; i++)
    {
      dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
      int sum = 0;
      for(int j = 1; j <= k; j++)
      {
        sum += dp[i-1][j];
      }


      for(int j = 1; j <= k; j++)
      {
        dp[i][j] = sum - dp[i-1][j];
      }

    }

    int ans = 0;
    for(int i = 1; i <= k; i++) ans += dp[n][i];


      cout << ans;
    return 0; 
}
