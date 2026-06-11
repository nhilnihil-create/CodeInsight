#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
  if(b == 0)return a;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}

int main(){
  int n;
  cin >> n;
  ll ans = 1;
  rep(i,n){
    ll t;
    cin >> t;
    ans = lcm(ans,t);
  }
  cout << ans << endl;
  return 0;
}