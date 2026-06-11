#include <bits/stdc++.h>
 
using namespace std;
 
#define x first

typedef long long ll;
const int mod = 1000000007;
const int oo = 1e9;
const int base = 27;
const int N = 100010;

typedef pair<int,int> pii;
 
int n , m ;
ll a[N],p1[N],p2[N];

void apply(ll a , ll b,int l , int r){
  if(l>r)return;
  p1[l] += a,p1[r+1] += -a,p2[l] += b , p2[r+1] -= b;
}
int main() {
  scanf("%d%d",&n,&m);
  for (int i = 1; i <= n; ++i)scanf("%lld",&a[i]);
  for (int i = 1; i+1 <= n; ++i){
    int s = a[i],t = a[i+1];
    if(s <= t){
      apply(-1,1+t,s+1,t); // -x+1+t
      apply(0,t-s,1,s); // t-s [1,s]
      apply(0,t-s,t+1,m);// t-s [t+1,m]
    }else{
      apply(-1,t+1+m,s+1,m); // - x + t  + 1 + m 
      apply(-1,1+t,1,t); // 1+t-x
      apply(0,m-s+t,t+1,s);//m-s+t
    }
  }
  ll ans = 1e18;
  for(int i= 1; i <= m ; ++i){
    p1[i] += p1[i-1],p2[i] += p2[i-1];
    ans = min(ans,p1[i]*i+p2[i]);
  }
  cout << ans << endl;
  return 0;
}