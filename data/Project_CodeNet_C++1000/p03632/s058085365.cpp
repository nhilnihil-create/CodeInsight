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
  int a,b,c,d; cin >> a >> b >> c >> d;
  int left = max(a,c), right = min(b,d);
  int ans = right - left;
  if(ans < 0) ans = 0;
  cout << ans << endl;
  return 0;
}
