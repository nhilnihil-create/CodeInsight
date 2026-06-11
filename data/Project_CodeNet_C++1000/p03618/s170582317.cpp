#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  string s;
  cin >> s;
  ll n = s.size();


  vector<ll> d1 (n);
  ll l=0, r=-1;
  for (ll i=0; i<n; ++i) {
    ll k = i>r ? 1 : min (d1[l+r-i], r-i+1);
    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
    d1[i] = k;
    if (i+k-1 > r)
      l = i-k+1,  r = i+k-1;
  }

  vector<ll> d2 (n);
  l=0, r=-1;
  for (ll i=0; i<n; ++i) {
    ll k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
    while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
    d2[i] = k;
    if (i+k-1 > r)
      l = i-k,  r = i+k-1;
  }

  ll num = accumulate(d1.begin(), d1.end(), 0LL);
  num += accumulate(d2.begin(), d2.end(), 0LL);

  ll result = n * (n + 1) / 2;
  if (num > 1) result -= num - 1;

  vector<ll> letters(26);
  for (char c : s) letters[c - 'a']++;
  ll num2 = 0;
  for (ll l : letters) num2 += l * (l - 1) / 2;

  result -= num2;

  for (ll x : d1) result += x - 1;
  for (ll x : d2) result += x;

  cout << result << endl;

  return 0;
}
