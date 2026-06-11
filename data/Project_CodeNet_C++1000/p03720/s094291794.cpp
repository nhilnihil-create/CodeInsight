#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,M = 0;
  cin >> N >> M;
  map <ll,ll> mp;
  rep(i,2*M){
    ll a = 0;
    cin >> a;
    mp[a]++;
  }
  for(ll i = 1; i <= N; i++){
    cout << mp[i] << endl;
  }
}