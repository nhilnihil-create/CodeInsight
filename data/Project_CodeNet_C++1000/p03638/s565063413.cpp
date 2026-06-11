#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

int main() {
  int H,W,N,a;
  cin >> H >> W >> N;
  queue<int> q;
  rep(i,N) {
    cin >> a;
    q.push(a);  
  }
  vector<vector<int>> ans(H,vector<int>(W));
  int now = q.front(),col=1;
  q.pop();
  rep(i,H){
    rep(j,W) {
      ans[i][j] = col;
      now--;
      if (now==0) {
        now = q.front();
        q.pop();
        col++;
      }
    }
  }

  rep(i,H){
    rep(j,W) {
      int res = ans[i][j];
      if (i%2) res = ans[i][W-1-j];
      cout << res << ' ';
    }
    cout << endl;
  }

} 