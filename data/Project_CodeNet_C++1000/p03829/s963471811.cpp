#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  long long A, B;
  cin >> N >> A >> B;
  vector<int> X(N);
  for (int i = 0; i < N; i++){
    cin >> X[i];
  }
  long long ans = 0;
  for (int i = 0; i < N - 1; i++){
    ans += min(B, A * (X[i + 1] - X[i]));
  }
  cout << ans << endl;
}