#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N,C,K;
  cin >> N >> C >> K;
  vector<int> T(N);
  rep(i,N) cin >> T[i];
  sort(T.begin(),T.end());
  int ans=0;
  for(int i=0; i<N;) {
    ans++;
    int start = i;
    while(i < N && T[i] - T[start] <= K && i - start < C) i++;
  }
  cout << ans << endl;
}