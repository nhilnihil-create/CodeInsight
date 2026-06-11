#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

void swap(ll* a, ll* b){
  ll tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(){
  ll N, X;
  cin >> N >> X;
  ll ans = N;

  ll a = X;
  ll b = N-X; // a > b;

  if(a < b) swap(&a, &b);


  //cout << ans << " " << a << " " << b << "\n";
  while(b){
    ll q = a/b;
    ll r = a%b;

    ans += (q*2*b);
    if(r == 0) ans -= b;
    a = b;
    b = r;
    //cout << ans << " " << a << " " << b << "\n";
  }
  cout << ans << "\n";
  return 0;
}