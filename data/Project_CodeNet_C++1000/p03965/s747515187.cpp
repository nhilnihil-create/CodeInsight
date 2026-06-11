#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int m = (n+1)/2;
  int ans = 0;
  rep(i,m) if(s[i]=='p') --ans;
  rep(i,n-m) if(s[m+i]=='g') ++ans;
  cout << ans << endl;
}