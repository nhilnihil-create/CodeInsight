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

llint x,y;

void solve(){
  cin >> x >> y;
  llint ans=inf;
  for(int i=0;i<4;i++){
    int t,s;
    llint z;
    if(i==0){
      t=x;
      s=y;
      z=s-t;
    }
    if(i==1){
      t=(-x);
      s=y;
      z=s-t+1;
    }
    if(i==2){
      t=x;
      s=(-y);
      z=s-t+1;
    }
    if(i==3){
      t=(-x);
      y=(-y);
      z=s-t+2;
    }
    if(z>=0)ans=min(ans,z);
  }
  cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
