#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;

int main(){
  ll n; cin >> n;
  vector<ll> v(3*n);
  for(ll i = 0; i < 3*n; i++){
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  ll sum = 0;
  for(ll i = 3*n-2; i > n-1; i -= 2){
    sum += v[i];
  }
  cout << sum << endl;
}