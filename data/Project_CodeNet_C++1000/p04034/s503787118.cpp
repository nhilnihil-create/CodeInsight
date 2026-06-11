#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
bool red[101010];
int main() {
  int N,M;
  cin >> N >> M;
  int box[N];
  for (int i = 0; i < N; i++) box[i] = 1;
  red[0] = true;
  
  for (int i = 0; i < M; i++) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    if (red[x]) {
      red[y] = true;
    }
    box[x]--;
    box[y]++;
    if (box[x] == 0) {
      red[x] = false;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (red[i]) ans++;
  } 
  cout << ans << endl;
  return 0;
}