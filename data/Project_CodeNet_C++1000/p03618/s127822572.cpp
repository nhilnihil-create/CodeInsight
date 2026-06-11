#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  string A; cin >> A;
  ll l = A.length();
  map<char,ll> count;
  rep(i,l) count[A[i]]++;
  ll result = l*(l-1)/2 + 1;
  for(auto x: count) result -= x.second*(x.second-1)/2;
  cout << result << endl;
  return 0;
}