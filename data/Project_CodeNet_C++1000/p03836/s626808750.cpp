#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main(){
  int a,b ,c,d;
  cin >> a >> b >> c>>d;
  int x=c-a;
  int y=d-b;
  rep(i,x)cout << 'R';
  rep(i,y+1)cout << 'U';
  rep(i,x+1)cout << 'L';
  rep(i,y+1)cout << 'D';
  cout << 'R';
  cout << 'D';
  rep(i,x+1)cout << 'R';
  rep(i,y+1)cout << 'U';
  rep(i,x+1)cout << 'L';
  rep(i,y)cout << 'D';
  cout << endl;
  
}