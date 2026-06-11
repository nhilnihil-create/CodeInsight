#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 10000000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n,k;
ll a[16];

int main(){
  cin >> n >> k;
  rep(i,0,n) cin >> a[i];
  int comb = (1<<k)-1;
  ll ans = INF;
  while(comb < 1 << n){

    ll u=0;//money
    ll z=0;
    rep(i,0,n){
      if(comb >> i & 1){
        if(z >= a[i]){
          z++;
          u += (z-a[i]);
        }
      }
      z = max(z,a[i]);
    }
    ans = min(ans,u);
    int x = comb & -comb, y = comb+x;
    comb = ((comb & ~y) / x>>1) | y;
  }
  cout<< ans << endl;

  return 0;
}
