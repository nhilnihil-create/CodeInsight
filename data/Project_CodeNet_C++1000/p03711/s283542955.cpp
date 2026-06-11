#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int x , y;
  int a[] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  cin >> x >> y;
  if(a[x] == a[y]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}