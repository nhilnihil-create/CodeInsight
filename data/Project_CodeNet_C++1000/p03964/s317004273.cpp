#include <iostream>
#include <cmath>

typedef long long ll;

using namespace std;

int main()
{
  ll n, t[1100], a[1100], score_t[1100], score_a[1100], nn, na, nt;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> t[i] >> a[i];
  }

  score_t[0] = score_a[0] = 1;
  for (int i = 0; i < n; i++)
  {
    if ((nt = score_t[i] / t[i] + (score_t[i] % t[i] == 0 ? 0 : 1)) > (na = score_a[i] / a[i] + (score_a[i] % a[i] == 0 ? 0 : 1)))
    {
      nn = nt;
    }
    else
    {
      nn = na;
    }
    score_a[i + 1] = a[i] * nn;
    score_t[i + 1] = t[i] * nn;
  }

  cout << score_a[n] + score_t[n] << endl;
}
