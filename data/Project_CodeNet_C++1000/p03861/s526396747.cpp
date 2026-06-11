#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll a, b, x;
  cin >> a >> b >> x;
  
  if (a > 0)
    cout << b / x - (a-1) / x << endl;
  else
    cout << b / x + 1 << endl;

  return 0;
}
