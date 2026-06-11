#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<endl
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define mp make_pair
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define sz(x) (int)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pll = pair<ll, ll>;
using vc = vector<char>;
using vvc = vector<vc>;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n,a;
  cin>>n>>a;
  vll x(n+1);
  rep(i,n) cin>>x[i+1];
  vector<vvll> dp(n+1,vvll(n+1,vll(a*n+1)));
  dp[0][0][0]=1;
  rep(i,n+1){
    rep(j,n+1){
      for(int u=0;u<=a*n;u++){
        if(i>=1&&u<x[i]) dp[i][j][u]=dp[i-1][j][u];
        else if(x[i]<=u&&j>=1&&i>=1)dp[i][j][u]=dp[i-1][j-1][u-x[i]]+dp[i-1][j][u];
      }
    }
  }
  ll ans=0;
  for(int i=1;i<=n;i++){
    ans+=dp[n][i][i*a];
  }
  COUT(ans);
}