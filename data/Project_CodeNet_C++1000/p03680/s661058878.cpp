#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int>a(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
    a[i]--;
  }
  
  int p = 0;
  int res = 0;
  bool undone = true;
  while(res < 10 * N) {
    res++;
    p = a[p];
    if(p == 1){
      undone = false;
      break;
    }
  }
  
  if(undone) cout << -1 << endl;
  else cout << res << endl;
}
