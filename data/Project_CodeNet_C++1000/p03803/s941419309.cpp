#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if(a == 1) a+= 100;
  if(b == 1) b+= 100;
  if(a > b) cout << "Alice" << endl;
  else if(a < b) cout << "Bob" << endl;
  else cout << "Draw" << endl;
  return 0;
}
