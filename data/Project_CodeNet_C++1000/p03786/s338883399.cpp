#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

ll gcd(ll x,ll y){
  if(x>y)swap(x,y);
  if(y%x==0)return x;
  return gcd(y-x*(y/x),x);
}

int main(){
  int n;cin >> n;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  vl sum(n);
  sum[0]=a[0];
  int ok=0;
  rep(i,n-1){
    sum[i+1]=sum[i]+a[i+1];
    if(a[i+1]>2*sum[i]){ok=i+1;}
  }

  cout << n-ok << endl;
}
