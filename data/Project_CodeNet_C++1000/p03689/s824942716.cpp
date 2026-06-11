#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int H,W,h,w;

vector<vector<int>> ans(505,vector<int>(505,1));

vector<int> A(505,1e8);
int main(){
  A[0] = 0;
  cin >> H >> W >> h >> w;
  if(H % h == 0 && W % w == 0){
    cout << "No" << endl;
    return 0;
  }
  bool s = false;
  if(H % h != 0 && W % w == 0){
    s = true;
    swap(H,W);
    swap(h,w);
  }
  A[w] = -1e8;
  rep(i,w + 1,W){
    A[i] = A[i - w] - 1;
  }
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      ans[i][j] = A[j + 1] - A[j];
    }
  }
  cout << "Yes" << endl;

  if(s){
    auto res = ans;
    for(int i = 0;i < H;i++){
      for(int j = 0;j < W;j++){
        res[j][i] = ans[i][j];
      }
    }
    swap(H,W);
    swap(h,w);
    ans = res;
  }
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      cout << ans[i][j] << " \n"[j == W - 1];
    }
  }
}

