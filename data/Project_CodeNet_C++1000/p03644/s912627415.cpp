#include <iostream>

typedef long long ll;

using namespace std;

int main()	{
  ll n;
  cin >> n;
  ll i = 1;
  for (i = 1; i <= n; i *= 2);
  if (i > n) i /= 2;
  cout << i << endl;
  return 0;
}