#include <bits/stdc++.h>
using namespace std;

int main() {

  long long N, M;
  cin >> N >> M;

  long long answer = 0;
  
  if (M <= N * 2) {
    answer = M / 2;
  } else {
    answer = N + (M - N * 2) / 4;
  }

  cout << answer <<  endl;

  return 0;

}