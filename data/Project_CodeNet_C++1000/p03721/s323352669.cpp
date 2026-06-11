#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;

int main(){
  ll n,k; cin >> n >> k;
  vector<pair<ll, ll>> ab(n);
  rep(i,n){
    cin >> ab.at(i).first >> ab.at(i).second;
  }

  sort(ab.begin(),ab.end());

  ll count = 0;
  rep(i,n) {
    count += ab.at(i).second;
    if(count >= k) {
      cout << ab.at(i).first << endl;
      break;
    }
  }
}
