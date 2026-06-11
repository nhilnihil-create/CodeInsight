#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N; cin >> N;
  vector<ll> num(N);
  for(ll i = 0; i < N; i++) {
    num.at(i) = i + 1;
  }
  ll cnt = 0;
  for(int j = 0; j < 1; ) {
    bool judge = false;
    for(ll i = 0; i < N; i++) {
      if(num.at(i) % 2 == 0) {
        //cout << num.at(i) << endl;
        num.at(i) /= 2;
        judge = true;
      }
    }
    if(judge) cnt++;
    else break;
  }
  ll x = pow(2, cnt);
  cout << x << endl;
}