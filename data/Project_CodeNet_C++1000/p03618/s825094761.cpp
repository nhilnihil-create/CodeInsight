#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  string a;
  cin >> a;
  ll n = a.size();
  

  vector<ll> alph(26, 0);
  ll ans = 0;
  for (int i = n-1; i >= 0; i--){
    ans += (n - 1 - i - alph[a[i]-'a']);
    alph[a[i]-'a']++;
  }

  ans++;
  cout << ans << endl;

  return 0;
}
