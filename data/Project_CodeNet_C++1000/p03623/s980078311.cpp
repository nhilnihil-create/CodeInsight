#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int x, a, b;
  cin >> x >> a >> b;

  if(abs(x-a) < abs(x-b))
    cout << "A";
  else
  {
    cout << "B";
  }


}
