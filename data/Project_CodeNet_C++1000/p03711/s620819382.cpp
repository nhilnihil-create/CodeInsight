#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define rep(i,a,n) for (int i =a; i<n; i++)
using namespace std;

int main() {
  int x,y,a,b; cin >> x >> y;
  if (x == 2) a = 2;
  else if (x == 4 || x == 6 || x == 9 || x == 11) a = 1;
  else a = 0;
  if (y == 2) b = 2;
  else if (y == 4 || y == 6 || y == 9 || y == 11) b = 1;
  else b = 0;
  if (a == b) cout << "Yes" << endl;
  else cout << "No" << endl;
}