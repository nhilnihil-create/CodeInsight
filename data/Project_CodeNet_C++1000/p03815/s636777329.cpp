#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  ll x;
  cin >> x;
  ll ans=0;
  ans+=(x/11)*2;
  x=x%11;
  if(x>=7){ans+=2;}else if(x>=1)ans++;
  cout << ans << endl;
}