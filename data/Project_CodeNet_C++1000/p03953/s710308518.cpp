#include <bits/stdc++.h>
using namespace std;

int N;
#define MAX_N 100000
int X[MAX_N], D[MAX_N - 1];
int M; long long K;
int P[MAX_N - 1];
bool Seen[MAX_N - 1];
vector<vector<int>> L;
int OL[MAX_N - 1], IL[MAX_N - 1];

int main() {
  cin >> N;
  for(int i = 0; i < N; ++i) cin >> X[i];
  for(int i = 0; i < N - 1; ++i) D[i] = X[i + 1] - X[i];
  cin >> M >> K;
  for(int i = 0; i < N - 1; ++i) P[i] = i;
  for(int i = 0; i < M; ++i) { int a; cin >> a; swap(P[a - 2], P[a - 1]); }
  for(int i = 0; i < N - 1; ++i) {
    if(!Seen[i]) {
      int j = i;
      int ol = L.size(); L.emplace_back();
      do {
        Seen[j] = true; OL[j] = ol; IL[j] = L[ol].size(); L[ol].push_back(j);
        j = P[j];
      } while(j != i);
    }
  }
  cout << X[0] << endl;
  long long tmp = X[0];
  for(int i = 0; i < N - 1; ++i) {
    vector<int>& loop = L[OL[i]];
    tmp += D[loop[(IL[i] + K) % loop.size()]];
    cout << tmp << endl;
  }
  return 0;
}
