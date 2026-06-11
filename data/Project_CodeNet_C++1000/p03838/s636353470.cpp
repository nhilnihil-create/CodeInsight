#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll x, y;
  cin >> x >> y;
  
  ll a = (y - x >= 0 ? y - x : INF);
  ll b = (y + x >= 0 ? y + x + 1 : INF);
  ll c = (-y - x >= 0 ? -y - x + 1 : INF);
  ll d = (-y + x >= 0 ? -y + x + 2 : INF);


  cout << min(a, min(b, min(c, d))) << endl;

  return 0;
}
