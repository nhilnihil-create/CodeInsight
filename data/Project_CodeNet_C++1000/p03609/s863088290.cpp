#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint>> que;
//priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int x,t;
void solve(){
  cin >> x >> t;
  if(x-t<0)cout << 0;
  else cout << x-t;
  cout << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
