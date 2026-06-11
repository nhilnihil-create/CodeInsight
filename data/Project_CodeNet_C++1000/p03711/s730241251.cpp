#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int x,y;
  cin >> x >> y;
  int a;
  if(x == 2) a = 3;
  else if(x % 2 == 0 && x < 8) a = 2;
  else if(x % 2 == 1 && x > 8) a = 2;
  else a = 1;
  int b;
  if(y == 2) b = 3;
  else if(y % 2 == 0 && y < 8) b = 2;
  else if(y % 2 == 1 && y > 8) b = 2;
  else b = 1;
  if(a == b) puts("Yes");
  else puts("No");
  return 0;
}
