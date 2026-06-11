#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))
 
using namespace std;
 
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  
  // 距離
  const int dx=tx-sx, dy=ty-sy;

  // 1
  cout<<string(dy,'U')<<string(dx,'R');
  
  // 2
  cout<<string(dy,'D')<<string(dx,'L');
  
  // 3
  cout<<'L'<<string(dy+1,'U')<<string(dx+1,'R')<<'D';
    
  // 3
  cout<<'R'<<string(dy+1,'D')<<string(dx+1,'L')<<'U';
  
  cout<<endl;
  
  return 0;
}