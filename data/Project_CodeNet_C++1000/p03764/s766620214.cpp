#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "math.h"
#include "cstring"
#include "stack"
#include "queue"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > mat;
ll mod = 1e9 + 7;

int main()
{
  int n, m;
  cin >> n >> m;
  ll x[100100];
  ll xans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
    xans += x[i] * (2 * i - n + 1);
    xans %= mod;
  }
  ll y[100100];
  ll yans = 0;
  for (int i = 0; i < m; i++)
  {
    cin >> y[i];
    yans += y[i] * (2 * i - m + 1);
    yans %= mod;
  }
  cout << (xans * yans + mod) % mod << "\n";
}