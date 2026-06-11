#include <bits/stdc++.h>
int distance(int a, int b) {
  int ans;
  if(a > b) ans = a - b;
  else ans = b - a;
  return ans;
}
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> x(N);
  int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> x.at(i);
    if(distance(x.at(i), K) > distance(x.at(i), 0)) sum += distance(x.at(i), 0);
    else sum += distance(x.at(i), K);
  }
  cout << sum * 2 << endl;
}