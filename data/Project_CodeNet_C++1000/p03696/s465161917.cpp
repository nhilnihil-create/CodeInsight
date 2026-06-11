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
  int n;string s;
  cin >> n >> s;
  int m = 0,d = 0;
  rep(i,n){
    if(s[i]=='(') ++d;
    else --d;
    m = min(m,d);
  }
  rep(i,-m) cout << '(';
  cout << s;
  rep(i,d-m) cout << ')';
  cout << endl;
}