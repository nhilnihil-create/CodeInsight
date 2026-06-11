#include<bits/stdc++.h>
using namespace std;

#define int long long

constexpr long long MOD = 1000000007;
constexpr long long INF = (long long)1e18;

signed main(){
  int H, W, h, w;
  int sum = 0;

  vector<vector<int>> ans;

  cin>>H>>W>>h>>w;

  ans.resize(H, vector<int>(W, 4000));

  for(int i = h-1; i < H; i += h){
    for(int j = w-1; j < W; j += w){
      ans[i][j] = - (h * w - 1)* 4000 - 1;
    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      sum += ans[i][j];
    }
  }

  // sum = 1;
  if(sum > 0) {
    cout<<"Yes"<<endl;
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        if(j) cout<<" ";
        cout<<ans[i][j];
      }
      cout<<endl;
    }
  } else {
    cout<<"No"<<endl;
  }
  return 0;
}
