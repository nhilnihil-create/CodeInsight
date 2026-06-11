#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  int a, b;
  int ans = 0;
  rep(i, n){
    cin >> a >> b;
    ans += b - a + 1;
  }
  cout << ans << endl;

  return 0;
}