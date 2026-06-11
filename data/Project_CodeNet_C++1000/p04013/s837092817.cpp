#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#define fi first
#define se second
#define pb(i) push_back(i)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define mes(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 55+10;
const int INF = 0x3f3f3f3f;
const int inf = - INF;
const int mod = 1e9+7;
const double pi = acos(-1.0);

ll x[N];
ll dp[N][N][N*N];
int main(){
    int n,a;
    cin>>n>>a;
    mes(dp,0);
    rep(i,1,n)
        cin>>x[i];
    rep(i,0,n){
        rep(j,0,n){
            rep(k,0,n*a){
                if(i==0&&j==0&&k==0) dp[i][j][k]=1;
                else if(i>=1&&k<x[i]) dp[i][j][k]=dp[i-1][j][k];
                else if(i>=1&&j>=1&&k>=x[i]) dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x[i]];
                else dp[i][j][k]=0;
            }
        }
    }
    ll ans=0;
    rep(i,1,n){
        ans+=dp[n][i][i*a];
    }
    cout<<ans<<endl;
    return 0;
}