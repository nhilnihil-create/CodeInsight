#include <bits/stdc++.h>
using namespace std;
int main(){
  int W, H;
  cin >> W >> H;
  vector<int> p(W);
  for (int i = 0; i < W; i++){
    cin >> p[i];
  }
  vector<int> q(H);
  for (int i = 0; i < H; i++){
    cin >> q[i];
  }
  vector<pair<int, char>> C;
  for (int i = 0; i < W; i++){
    C.push_back(make_pair(p[i], 'p'));
  }
  for (int i = 0; i < H; i++){
    C.push_back(make_pair(q[i], 'q'));
  }
  sort(C.begin(), C.end());
  int N = C.size();
  long long ans = 0;
  for (int i = 0; i < N; i++){
    if (C[i].second == 'p'){
      ans += (long long) C[i].first * (H + 1);
      W--;
    } else {
      ans += (long long) C[i].first * (W + 1);
      H--;
    }
  }
  cout << ans << endl;
}