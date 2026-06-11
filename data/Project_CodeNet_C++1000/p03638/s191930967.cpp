#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <climits>
#include <bitset>
#include <utility>


using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// const ll INF = 1LL <<60;
const ll INF = 	922337203685477580;

//最小公倍数
ll gcd(ll x, ll y) {
  ll tmp = 0;
  if (x < y){
    tmp=x;
    x=y;
    y=tmp;
  }
  while (y > 0) {
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

//最大公倍数
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}

//階乗
ll kaijo(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        sum%=1000000000+7;
    }
    return sum;
}

//for(int i = ; i < ; i++){}

ll lmax(ll s,ll t){
  if(s>t){
    return s;
  }
  else{
    return t;
  }
}

ll lmin(ll s,ll t){
  if(s<t){
    return s;
  }
  else{
    return t;
  }
}
// ここから開始
ll dp[100010];

int main(){
  int h,w;
  int n;
  cin>>h>>w>>n;
  int a[n];
  for(int i = 0; i < n; i++) cin>>a[i];
  int p[h][w];
  int cnt=0;
  int flg = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(cnt==a[flg]){
        flg+=1;
        cnt=0;
      }

      if(i%2==0)p[i][j]=flg+1;
      else p[i][w-1-j]=flg+1;
      cnt++;
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout<<p[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
