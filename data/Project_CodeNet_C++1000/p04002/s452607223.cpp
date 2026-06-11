#include <bits/stdc++.h>
using namespace std;

int main(){
  long long H, W, N;
  cin >> H >> W >> N;
  map<pair<int, int>, int> mp;
  for (int i=0; i<N; i++){
    int a, b; cin >> a >> b;
    for (int x=-1; x<=1; x++){
      for (int y=-1; y<=1; y++){
        if (a+x<=1||a+x>=H||b+y<=1||b+y>=W) continue;
        mp[make_pair(a+x, b+y)]++;
      }
    }
  }
  vector<long long> ans(10,0);
  for (auto k: mp){
    // cout << k.first.first << ' ' << k.first.second << endl;
    ans[k.second]++;
  }
  long long sum = 0;
  for (int i=1; i<=9; i++){
    sum += ans[i];
  }
  ans[0] = (H-2)*(W-2) - sum;
  for (int i=0; i<=9; i++){
    cout << ans[i] << endl;
  }
}
