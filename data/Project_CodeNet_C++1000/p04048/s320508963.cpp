#include <iostream>

using namespace std;

using ll = long long;

ll f(ll a, ll b){
  if(a < b)
    swap(a, b);
  if(b == 0)
    return -a;
  else {
    return f(a % b, b) + 2 * b * (a / b);
  }
}

int main()
{
  ll n, x;
  cin >> n >> x;
  cout << n + f(n - x, x);
  return 0;
}
