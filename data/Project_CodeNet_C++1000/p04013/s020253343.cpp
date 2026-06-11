#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

int main()  {
    int n,a;
    cin>>n>>a;
    ll x[n];
    for(int i=0;i<n;i++)    {
        cin>>x[i];
        x[i]-=a;
    }
    ll dp[n+1][2*a*n+1]={};
    dp[0][n*a]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<2*a*n;j++)    {
            if(j-x[i]<0 || j-x[i]>2*a*n)    {
                dp[i+1][j+1]=dp[i][j+1];
            }
            else
                dp[i+1][j+1]=dp[i][j+1]+dp[i][j+1-x[i]];
        }
    cout<<dp[n][a*n]-1<<endl;
    return 0;
}
