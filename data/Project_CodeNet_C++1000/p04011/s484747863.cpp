#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{

  int a,b,c,d;
  cin >>a>>b>>c>>d;
  if (a <= b) cout << c * a << endl;
  else cout << b* c + (a - b) * d << endl;
  return 0;
}
