#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int64;
 
int main()
{
  int N, W;
  int w1;
  cin >> N >> W;
 
  vector< int > st[4];
  for(int i = 0; i < N; i++) {
    int w, v;
    cin >> w >> v;
    if(i == 0) w1 = w;
    st[w - w1].push_back(v);
  }
  for(int i = 0; i < 4; i++) {
    sort(begin(st[i]), end(st[i]));
    st[i].push_back(0);
    reverse(begin(st[i]), end(st[i]));
    for(int j = 1; j < st[i].size(); j++) {
      st[i][j] += st[i][j - 1];
    }
  }
 
  int ret = 0;
  for(int64 i = 0; i < st[0].size(); i++) {
    for(int64 j = 0; j < st[1].size(); j++) {
      for(int64 k = 0; k < st[2].size(); k++) {
        for(int64 l = 0; l < st[3].size(); l++) {
          int64 fact = w1 * i + (w1 + 1) * j + (w1 + 2) * k + (w1 + 3) * l;
          if(fact <= W) {
            ret = max(ret, st[0][i] + st[1][j] + st[2][k] + st[3][l]);
          }
        }
      }
    }
  }
 
  cout << ret << endl;
}