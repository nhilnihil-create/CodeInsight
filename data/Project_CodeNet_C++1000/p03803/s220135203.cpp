#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
 
int main()
{
  int a, b, c;
  cin >> a >> b;
  if(a == b) cout << "Draw" << endl;
  else if(a == 1 || b != 1 && a > b) cout << "Alice" << endl;
  else cout << "Bob" << endl;
  return 0;
}
