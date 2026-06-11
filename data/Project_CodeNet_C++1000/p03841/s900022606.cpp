#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> Q;
int R[500 * 500];

int main() {
  cin >> N;
  for(int i = 1; i <= N; ++i) {
    int x; cin >> x; --x; Q.push_back(make_pair(x, i));
  }
  sort(Q.begin(), Q.end());
  int h = 0;
  for(int q = 0; q < N; ++q) {
    int x = Q[q].first, i = Q[q].second;
    R[x] = i;
    int d = 0;
    while(d < i - 1) {
      if(!R[h]) { R[h] = i; ++d; }
      ++h;
      if(h > x) { cout << "No" << endl; return 0; }
    }
  }
  h = N * N - 1;
  for(int q = N - 1; q >= 0; --q) {
    int x = Q[q].first, i = Q[q].second;
    int d = 0;
    while(d < N - i) {
      if(!R[h]) { R[h] = i; ++d; }
      --h;
      if(h < x) { cout << "No" << endl; return 0; }
    }
  }
  cout << "Yes" << endl;
  for(int i = 0; i < N * N; ++i) cout << (i == 0 ? "" : " ") << R[i];
  cout << endl;
  return 0;
}
