#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int large = max(a, max(b, c));
  int all = a+b+c;
  if(large == all-large) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
