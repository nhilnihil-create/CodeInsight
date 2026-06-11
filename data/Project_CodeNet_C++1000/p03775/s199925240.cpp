#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int digit_cnt(ll n, ll m){
  int cnt=0;
  while(n>0 || m>0){
    n/=10; m/=10;
    cnt++;
  }
  return cnt;
}

const int INF=INT_MAX;

int main(){
  ll n;
  cin>>n;
  int ans=INF;
  for(ll i = 1; i*i <= n; i++){
    if(n%i == 0){
      ans = min(ans,(digit_cnt(i,n/i)));
    }
  }
  cout<<ans<<endl;
}