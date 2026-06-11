#include <iostream>

typedef long long ll;

using namespace std;

int main()	{
  ll n;
  cin >> n;
  ll x;
  ll n_2s = 0, n_4s = 0;
  for (int i = 0; i < n; i++)	{
    cin >> x;
    if (x % 2 == 0 && x % 4)	{
      n_2s++;
    }
    else if (x % 4 == 0)	{
      n_4s++;
    }
  }
  if (n_2s / 2 + n_4s >= n / 2)	{
    cout << "Yes" << endl;
  }
  else	{
    cout << "No" << endl;
  }
  return 0;
}