#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int dist1[200010], dist2[200010];
vector<int> x[200010];

void dfs1(int pos, int depth) {
  if(dist1[pos] != -1) return ;
  dist1[pos] = depth;
  for(int i = 0; i < x[pos].size(); ++i) {
    dfs1(x[pos][i], depth+1);
  }
}

void dfs2(int pos, int depth) {
  if(dist2[pos] != -1) return ;
  dist2[pos] = depth;
  for(int i = 0; i < x[pos].size(); ++i) {
    dfs2(x[pos][i], depth+1);
  }
}

int main() {
  int N; cin >> N;
  vector<int> a(N), b(N);
  for(int i = 0; i < N-1; ++i) {
    cin >> a[i] >> b[i];
    x[a[i]].push_back(b[i]);
    x[b[i]].push_back(a[i]);
  }
  for(int i = 0; i < 200010; ++i) {
    dist1[i] = -1;
    dist2[i] = -1;
  }
  dfs1(1, 0);
  dfs2(N, 0);
  int cnt1 = 0, cnt2 = 0;
  for(int i = 1; i <= N; ++i) {
    (dist1[i] <= dist2[i]) ? cnt1++ : cnt2++;
  }
  if(cnt1 > cnt2) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;
  return 0;
}
