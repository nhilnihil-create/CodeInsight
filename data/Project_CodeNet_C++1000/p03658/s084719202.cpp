#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, b;
  cin >> n >> b;
  int c[n];
  rep(i, n){
    cin >> c[i];
  }
  int ans = 0;
  sort(c, c + n);
  reverse(c, c + n);
  rep(i, b){
    ans += c[i];
  }
    
  

  cout << ans << endl;
  return 0;
}
