#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
  int h,w;
  cin >> h >> w;
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  vector<vector<int>> maze(h,vector<int>(w,0));
  int now = 0;
  rep(i,h){
    if(i%2 == 0){
      for(int j=0;j<w;j++){
        maze.at(i).at(j) = now;
        a.at(now) --;
        if(a.at(now) == 0) now ++;
      }
    }else{
      for(int j=w-1;j>=0;j--){
        maze.at(i).at(j) = now;
        a.at(now) --;
        if(a.at(now) == 0) now ++;
      }
    }
  }
  rep(i,h){
    rep(j,w){
      cout << maze.at(i).at(j) + 1 ;
      if(j == w-1) cout << endl;
      else cout << ' ';
    }
  }  
        
  return 0;
}


