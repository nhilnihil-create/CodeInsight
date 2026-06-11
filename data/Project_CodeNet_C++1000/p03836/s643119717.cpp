#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<vector<int>> vec(2010, vector<int>(2010, 0));

char rev(char c) {
  switch(c) {
    case 'R':
      return 'L';
    case 'L':
      return 'R';
    case 'U':
      return 'D';
    case 'D':
      return 'U';
  }
  return 'U';
}

int main()
{
  int sx, sy, tx, ty;
  int cx, cy;
  cin >> sx >> sy >> tx >> ty;
  cx = sx;
  cy = sy;
  string tmp = "";
  string ans = "";
  while(cy < ty) {
    tmp += 'U';
    cy++;
  }
  while(cx < tx) {
    tmp += 'R';
    cx++;
  }
  ans += tmp;
  rep(i, (int)tmp.size()) ans += rev(tmp.at(i));
  tmp = "L";
  cx = sx - 1, cy = sy-1;
  while(cy < ty) {
    tmp += 'U';
    cy++;    
  }
  while(cx < tx) {
    tmp += 'R';
    cx++;
  }
  tmp += 'D';
  ans += tmp;
  rep(i, (int)tmp.size()) ans += rev(tmp.at(i));
  cout << ans << endl;
  
  return 0;
}