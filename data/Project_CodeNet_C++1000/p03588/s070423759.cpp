#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long int;
using namespace std;
ll mod=1e9+7;


int main() {
  int n;
  cin >> n;
  ll ans=0;
  ll q=0,r=0;
  rep(i,n){
    ll a,b;
    cin >> a>> b;
    if(q<a){
      q=a;
      r=b;
    };
  }
  cout << q+r << endl;
}