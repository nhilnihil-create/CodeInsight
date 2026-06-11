#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  
  vector<int> a(N);
  for (int i=0; i<N; i++) {
    cin >> a.at(i);
  }
  
  int cnt = 0, p = 1;
  while(1) {
    p = a.at(p-1);
    cnt++;
    if (p==2) break;
    if (cnt==N) {
      cnt = -1;
      break;
    }
  }
  
  cout << cnt << endl;
  
  return 0;
}
