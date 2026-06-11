#include <assert.h>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

//const ll MOD = 998244353;
const ll MOD = 1e9+7;


 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,k;
  std::cin>>n>>k;
  std::vector<ll> a(n);
  rep(i,0,n)std::cin>>a[i];
  std::sort(all(a));

  ll left=-1,right=n;
  std::vector<std::vector<bool>> dp(n, std::vector<bool>(k, false));
  while(right-left>1){
    ll mid=left+(right-left)/2;
    bool flag = false;

    if(a[mid]>=k){
      flag=true;
    }else{
      rep(i,1,k)dp[0][i]=false;
      dp[0][0]=true;
      rep(i,0,n-1){
        ll temp=i;
        if(temp>=mid)temp++;
        rep(j,0,k){
          dp[i+1][j]=dp[i][j]|dp[i][(j-a[temp]>=0)?j-a[temp]:j];
        }
      }
      rep(i,k-a[mid],k)flag=(flag|dp[n-1][i]);
    }
    if(flag)right=mid;
    else left=mid;
  }

  std::cout<<left+1;
  return 0;
}