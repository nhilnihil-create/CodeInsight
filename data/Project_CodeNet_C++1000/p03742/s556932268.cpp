#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
  ll a, b;
  cin >> a >> b;
  if(max(a, b) - min(a, b) >= 2)
  {
    cout << "Alice" << endl;
  }
  else cout << "Brown" << endl;
}