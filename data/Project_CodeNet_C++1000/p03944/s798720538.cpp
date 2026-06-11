#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
  int w, h, n;
  cin >> w >> h >> n;
  vector<vector<bool>>board(h, vector<bool>(w, false));
  rep(i, 0, n){
    int x, y, a;
    cin >> x >> y >> a;
    if(a==1){
      rep(j, 0, h){
        rep(k, 0, x){
          board[j][k]=true;
        }
      }
    }
    if(a==2){
      rep(j, 0, h){
        rep(k, x, w){
          board[j][k]=true;
        }
      }
    }
    if(a==3){
      rep(j, 0, y){
        rep(k, 0, w){
          board[j][k]=true;
        }
      }
    }
    if(a==4){
      rep(j, y, h){
        rep(k, 0, w){
          board[j][k]=true;
        }
      }
    }
  }
  int ans = 0;
  rep(i, 0, h)rep(j, 0, w)if(board[i][j]==false)ans++;
  cout << ans << endl;
}