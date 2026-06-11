#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e9;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> color(N);
  for (int i = 0; i < N; i++) {
    cin >> color[i];
  }

  vector<vector<int> > G(H, vector<int>(W));
  int key = 0;
  for (int i = 0; i < H; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < W; j++) {
        G[i][j] = key;
        color[key]--;
        if (color[key] == 0) {
          key++;
        }
      }
    } else {
      for (int j = W - 1; j >= 0; j--) {
        G[i][j] = key;
        color[key]--;
        if (color[key] == 0) {
          key++;
        }
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << G[i][j] + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}
