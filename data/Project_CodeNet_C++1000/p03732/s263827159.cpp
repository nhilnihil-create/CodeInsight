#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
  int n, m;
  int o;
  cin >> n >> m;
 
  vector<int>x[4];
  for(int i = 0; i < n; i++) {
    int a,b;
    cin >> a >> b;
    if(i == 0) o = a;
    x[a-o].push_back(b);
  }
  for(int i = 0; i < 4; i++) {
    sort(begin(x[i]), end(x[i]));
    x[i].push_back(0);
    reverse(begin(x[i]), end(x[i]));
    for(int j = 1; j < x[i].size(); j++) {
      x[i][j] += x[i][j - 1];
    }
  }
 
  int ans = 0;
  for(ll i = 0; i < x[0].size(); i++) {
    for(ll j = 0; j < x[1].size(); j++) {
      for(ll k = 0; k < x[2].size(); k++) {
        for(ll l = 0; l < x[3].size(); l++) {
          ll ann = o * i + (o + 1) * j + (o + 2) * k + (o + 3) * l;
          if(ann <= m) {
            ans = max(ans,x[0][i]+x[1][j]+x[2][k]+x[3][l]);
          }
        }
      }
    }
  }
 
  cout << ans << endl;
}
