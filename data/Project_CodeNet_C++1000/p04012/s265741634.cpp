#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define all(a) a.begin(), a.end()
#define x first
#define y second
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  // cout << s;
  int flag = 1;
  int n = s.size();
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1] && flag)
      flag = 0;
    else if (s[i] != s[i - 1] && flag)
      break;
    else
      flag = 1;
    // cout << flag << " ";
  }
  if (flag)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}