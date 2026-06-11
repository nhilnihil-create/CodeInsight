#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  string s, t;
  cin >> s >> t;
  ll n = s.size();
  ll m = s.size();
  
  ll q;
  cin >> q;

  vector<ll> u(n + 1, 0), v(m + 1, 0);
  for (int i = 1; i <= n; i++){
    if (s[i-1] == 'A'){
      u[i] = (u[i-1] + 1);
    }
    else {
      u[i] = (u[i-1] + 2);
    }
  }
  for (int i = 1; i <= m; i++){
    if (t[i-1] == 'A'){
      v[i] = (v[i-1] + 1);
    }
    else {
      v[i] = (v[i-1] + 2);
    }
  }
 
  for (int i = 0; i < q; i++){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((u[b] - u[a-1]) % 3 == (v[d] - v[c-1]) % 3)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  

  return 0;
}
