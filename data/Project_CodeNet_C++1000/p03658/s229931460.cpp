#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> length(N);
  for(int i = 0; i < N; i++) cin >> length.at(i);
  
  sort(length.begin(), length.end(), greater<int>());
  int sum = 0;
  for(int i = 0; i < K; i++){
    sum += length.at(i);
  }
  
  cout << sum << endl;

  return 0;
}
