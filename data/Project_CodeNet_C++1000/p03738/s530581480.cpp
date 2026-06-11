#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  string a,b; cin >> a >> b;
  int al = a.size();
  int bl = b.size();
  string ans = "EQUAL";
  if(al < bl) ans = "LESS";
  else if(al > bl) ans = "GREATER";
  else{
    for(int i = 0; i < al; i++){
      int an = a[i] - '0', bn = b[i] - '0';
      if(an == bn) continue;
      if(an < bn) ans = "LESS";
      else ans = "GREATER";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
