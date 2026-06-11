#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

ll gcd(ll a,ll b){
  if(a%b==0) return b;
  else return gcd(a,a%b);
}
ll lcm(ll a,ll b){
  ll g = gcd(a,b);
  return a/g*b;
}

int main(){
  ll x,y;
  cin >> x >> y;
  ll ans = INFL;

  if(y>x) ans = min(ans,y-x);
  if(y>=-x) ans = min(ans,y+x+1);
  if(-y>x) ans = min(ans,-y-x+1);
  if(-y>-x) ans = min(ans,-y+x+2);

  cout << ans << endl;
}
