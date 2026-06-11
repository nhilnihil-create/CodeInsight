#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> a(N);
  
   for(int i = 0; i < N ; i++) {
     cin >> a.at(i);
  }
  
  int s = 1, cnt = 1;
  for(int i = 0; i < N; i++) {
    s = a.at(s-1);
    if(s == 2) {
      cout << cnt << endl;
      break;
    }
    cnt++;
  }
  
  if(s != 2) {
    cout << -1 << endl;
  }
}
