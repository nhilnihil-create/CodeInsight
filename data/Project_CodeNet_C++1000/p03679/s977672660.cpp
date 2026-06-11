#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  ll x,a,b;
  cin >> x >> a >> b;
  if(a>=b)
    cout << "delicious" << endl;
  else if(b-a<=x)
    cout << "safe" << endl;
  else
    cout << "dangerous" << endl;
}