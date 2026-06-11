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
typedef vector<int> vi;
typedef vector<ll> vll;

vi Solve(ll n) {
  if (n == 0) exit(0);
  if (n == 1) return vi(0, 0);
  vi a = Solve(n / 2);
  a.push_back(a.size());
  if (n % 2) {
    reverse(a.begin(), a.end());
    a.push_back(a.size());
    reverse(a.begin(), a.end());
  }
  return a;
}

int main()
{
  ll n;
  cin >> n;
  vi result = Solve(n + 1);

  int m = result.size();
  for (int i = 0; i < m ; ++i) result.push_back(i);
  cout << result.size() << endl;
  for (int i = 0; i < result.size(); ++i) {
    if (i) cout << " ";
    cout << result[i] + 1;
  }
  cout << endl;

  return 0;
}
