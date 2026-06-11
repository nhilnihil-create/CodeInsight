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
  int h,w; cin >> h >> w;
  char g[h][w];
  rep(i,h)rep(j,w){
    cin >> g[i][j];
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << g[i][j];
    }
    cout << endl;
    for(int j = 0; j < w; j++){
      cout << g[i][j];
    }
    cout << endl;
  }
  return 0;
}
