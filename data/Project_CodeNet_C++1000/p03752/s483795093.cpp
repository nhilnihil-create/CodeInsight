#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};



int main(){

  int n,k;
  cin >> n >> k;
  vector<ll> h(n);
  REP(i,n)cin >> h[i];
  ll res = (1ll << 60);
  for(int bit = 1;bit < (1 << n);bit++){
    vector<bool> is(n,0);
    REP(i,n)if(bit >> i & 1)is[i] = true;
    ll height = 0;
    ll sum = 0;
    int c = 0;
    REP(i,n){
      if(!is[i]){
        if(h[i] > height)c++;
        height = max(height,h[i]);
        continue;
      }
      c++;
      if(h[i] <= height)sum += height-h[i]+1;
      height = max(h[i],height+1);
    }
    if(c >= k)res = min(res,sum);
  }

  cout << res << endl;
  



  return 0;
}