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
  int n,k; cin >> n >> k;
  vector<int> l(n);
  rep(i,n) cin >> l[i];
  sort(l.begin(), l.end());
  reverse(l.begin(), l.end());
  int ans = 0;
  for(int i = 0; i < k; i++){
    ans += l[i];
  }
  cout << ans << endl;
  return 0;
}
