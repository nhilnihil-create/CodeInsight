#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  ll a,b;
  cin >>a >>b;
  ll cnt = 0;
  bool zero = false;
  for(ll i = a; i<=b; i++){
    if(i<0) cnt++;
    if(i==0) zero = true;
  }
  if(zero) cout << "Zero" << endl;
  else if(cnt%2 == 0) cout << "Positive" << endl;
  else cout << "Negative" << endl;
  return 0;
}