#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

typedef long long ll;

using namespace std;

int main()	{
  ll x, t;
  cin >> x >> t;
  cout << max(int(x - t), 0) << endl;
  return 0;
}