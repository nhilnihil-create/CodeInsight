#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

int const N = 2500; 
int n, A, v[N];
ll dp[50][50][N];

ll go(int i, int t, int av){
      if(i == n){
         if(!t)return 0;
         return (av % t == 0) && (av / t) == A;
      }
      ll &ret = dp[i][t][av];
      if(ret + 1)return ret;
      ret = 0;
      ret = (ll) (ret + go(i+1, t, av));
      ret = (ll) (ret + go(i+1, t+1, av+v[i]));
      return ret;
}

int main(){
    scanf("%d%d", &n, &A);
    for(int i = 0; i<n; ++i)scanf("%d", v+i);
    memset(dp, -1, sizeof dp);
    ll an = go(0,0,0);
    printf("%lld\n", an);
} 