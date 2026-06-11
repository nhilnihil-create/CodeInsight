#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll a, b, c;
  cin >> a >> b >> c;
  
  cout << min((a % 2) * (b*c), min((b % 2) * a*c, (c % 2)*a*b)) << endl;

  return 0;
}
