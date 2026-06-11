#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <unordered_map>

using namespace std;

typedef long long ll;

int main()	{
  ll n;
  cin >> n;
  unordered_map<ll, ll> freq;
  ll a[n] = {0};
  for (ll i = 0; i < n; i++)	{
    cin >> a[i];
    freq[a[i]]++;
  }
  ll max_freq = 0, smax_freq = 0;
  sort(a, a + n, greater<ll>());
  for (ll i = 0; i < n; i++)	{
    if (freq[a[i]] >= 4 && max_freq == 0 && smax_freq == 0)	{
      max_freq = a[i];
      smax_freq = a[i];
      break;
    }
    else if (freq[a[i]] >=2 && max_freq == 0)	{
      max_freq = a[i];
    }
    else if (freq[a[i]] >= 2 && max_freq != 0 && max_freq != a[i])	{
      smax_freq = a[i];
    }
    if (max_freq != 0 && smax_freq != 0)	{
      break;
    }
  }
  cout << smax_freq * max_freq << endl;
  return 0;
}