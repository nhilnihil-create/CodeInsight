#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, K, temp, res = 0;
  cin >> N >> K;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) {
    cin >> temp;
    res += min(temp * 2,(K - temp) * 2);
  }
  cout << res << endl;
}