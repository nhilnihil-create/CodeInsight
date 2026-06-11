#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int sum = 0;
  for (int i = 1; i <= N; i++) {
	int x;
    cin >> x;
    
    sum += min(x, K - x) * 2;
  }
  cout << sum << endl;
}
