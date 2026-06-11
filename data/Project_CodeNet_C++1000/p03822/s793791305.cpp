#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int N;
int M[110000];
vector<int> lis[110000];

int Depth(int a) {
  if (lis[a].empty()) {
    return 0;
  } else {
    int mx = 0;
    vector<int> K;
    for (int i = 0; i < (int)lis[a].size(); i++) {
      K.push_back(Depth(lis[a][i]));
    }
    sort(K.begin(),K.end());
    reverse(K.begin(),K.end());
    for (int i = 0; i < (int)K.size(); i++) {
      mx = max(mx, K[i] + (i+1));
    }
    return mx;
  }
}

int main() {
  cin >> N;
  for (int i = 1; i < N; i++) {
    cin >> M[i];
    M[i]--;
    lis[M[i]].push_back(i);
  }
  cout << Depth(0) << endl;
  return 0;
}