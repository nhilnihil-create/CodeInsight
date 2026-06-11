
#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;
  typedef long long ll;
  ll T, A;
  cin >> T >> A;
  ll t = T, a = A;
  for (int i = 1; i < N; ++i)
  {
    cin >> T >> A;
    ll m = t/T + ((0 == t%T) ? 0 : 1);
    ll n = a/A + ((0 == a%A) ? 0 : 1);
    ll j = ((m < n) ? n : m);
    t = j*T;
    a = j*A;
  }
  cout << t + a;
  return 0;
}
