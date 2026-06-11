#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
  int w,a,b;
  cin >> w >> a >> b;
  cout << max(0, max(b - (a + w), a - (b + w))) << endl;
}