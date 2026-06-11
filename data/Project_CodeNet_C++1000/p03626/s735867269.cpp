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

llint n;
string s1,s2;

void solve(){
  cin >> n;
  cin >> s1 >> s2;
  int p=-1;
  llint ans=1;
  for(int i=0;i<n;i++){
    if(s1[i]==s2[i]){//縦積み
      if(p==-1)ans*=3;
      if(p==0)ans*=2;
      p=0;
    }
    else{//横積み
      if(p==-1)ans*=6;
      if(p==0)ans*=2;
      if(p==1)ans*=3;
      p=1;
      i++;
    }
    ans%=mod;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}
