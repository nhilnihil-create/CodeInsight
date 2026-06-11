#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n, m;
  cin >> n >> m;
  
  vector<int> c(n);
  for (int i = 0; i < m; i++){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    c[a] = (c[a] + 1) % 2;
    c[b] = (c[b] + 1) % 2;
  }

  int ok = 1;
  for (int i = 0; i < n; i++){
    if(c[i] == 1)
      ok = 0;
  }
  if(ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
