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

llint x;

void solve(){
  cin >> x;
  llint ans=x/11*2;
  if(x%11==0)ans+=0;
  else if(x%11>6)ans+=2;
  else ans++;
  cout << ans <<  endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
