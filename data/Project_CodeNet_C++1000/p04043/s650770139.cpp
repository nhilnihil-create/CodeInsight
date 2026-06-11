#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  map<ll, ll> mp;
  rep(i,3){
    int n; cin >> n;
    mp[n]++;
  }
  if(mp[5] == 2 && mp[7] == 1){
    cout << "YES";
  }
  else{
    cout << "NO";
  }
}