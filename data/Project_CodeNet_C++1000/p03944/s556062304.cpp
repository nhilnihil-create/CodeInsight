#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int W,H,N; cin >>W >>H >>N;

  vector<vector<bool>> vec(W, vector<bool>(H));

  rep(i,0,N) {
    int x,y,a; cin >>x >>y >>a;
    if (a==1) {
      rep(i,0,x) {
        rep(j,0,H) {
          vec[i][j]=true;
        }
      }
    } else if (a==2) {
      rep(i,x,W) {
        rep(j,0,H) {
          vec[i][j]=true;
        }
      }
    } else if (a==3) {
      rep(i,0,W) {
        rep(j,0,y) {
          vec[i][j]=true;
        }
      }
    } else {
      rep(i,0,W) {
        rep(j,y,H) {
          vec[i][j]=true;
        }
      }
    }
  }

  int ans=0;

  rep(i,0,W) {
    rep(j,0,H) {
      if (vec[i][j]==false) ans++;
    }
  }

  cout <<ans <<endl;
  return 0;
}
