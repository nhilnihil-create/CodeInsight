#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N, M;
  cin >> N >> M;

  cout << min(N, M/2) + max((M-(N*2))/4, 0LL) << endl;

  return 0;
}
