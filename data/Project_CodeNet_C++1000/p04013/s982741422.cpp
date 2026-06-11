#include<bits/stdc++.h>
#include<numeric>
using namespace std;
#define ll  long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<ll,ll>
#define pb push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// using ll = long long;
ll int dp[55][55][55*55];
ll int A[55];
int main()
{
    int n,a;
    cin >> n >> a;
    for(int i=0;i<n;i++)
    cin >> A[i];
    dp[0][0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=50*50;k++)
            {
                dp[i+1][j][k] += dp[i][j][k];
                dp[i+1][j+1][k+A[i]] += dp[i][j][k];
            }
        }
    }
    ll int total = 0;
    for(int i=1;i<=n;i++)
    {
        total += dp[n][i][i*a];
    }
    cout << total;
}