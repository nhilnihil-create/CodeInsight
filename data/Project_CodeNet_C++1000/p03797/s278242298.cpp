#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N, M;
  cin >> N >> M;

  cout << (M-2*N >= 0 ? N+(M-N*2)/4 : M/2) << endl;

  return 0;
}
