#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint>> que;
//priority_queue<llint> q;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int x,a,b;

void solve(){
  cin >> x >> a >> b;
  int c=abs(x-a),d=abs(x-b);
  if(c>d)cout << "B";
  else cout << "A";
  cout << endl;
}

int main() {
  solve();
  return 0;
}
