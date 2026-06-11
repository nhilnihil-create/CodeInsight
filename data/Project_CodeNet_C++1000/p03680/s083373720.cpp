#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, banti = 1, res = 1;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec[i];
  for(int i = 0; i < N; i++) {
    if(vec[banti-1] == 2) {
      cout << res << endl;
      return 0;
    }
    banti = vec[banti-1];
    res++;
  }
  cout << -1 << endl;
  return 0;
}
    