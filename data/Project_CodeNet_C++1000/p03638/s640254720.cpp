#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int h,w,n;
  cin >> h >> w >> n;
  vi a(n);
  vvi board(h, vi(w));
  rep(i, n) cin >> a[i];
  int cur = 0;
  rep(y, h){
    if(y % 2 == 0){
      rep(x, w){
        if(!a[cur]) cur++;
        a[cur]--;
        board[y][x] = cur + 1;
      }
    }else{
      for(int x = w - 1; x >= 0; x--){
        if(!a[cur]) cur++;
        a[cur]--;
        board[y][x] = cur + 1;
      }
    }
  }
  rep(y, h){
    rep(x, w){
      cout << board[y][x];
      if(x != w - 1) cout << " ";
    }
    cout << endl;
  }
}