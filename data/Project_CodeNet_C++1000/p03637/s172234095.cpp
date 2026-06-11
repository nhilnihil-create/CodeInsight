#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n; cin>>n;
  vector<ll> c2,c4;
  for(int i=0; i<n; i++) {
    ll x; cin>>x;
    if(x%4==0) c4.push_back(x);
    else if(x%2==0) c2.push_back(x);
  }
  cout << (c4.size() + c2.size()/2 >= n/2 ? "Yes" : "No");
}