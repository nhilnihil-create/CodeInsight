#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum=0, light=1;
  cin >> N;
  
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A.at(i);
  }
  
  while (light != 2) {
    sum++;
    light = A.at(light-1);
    
    if (sum > N+1) {
      cout << -1 << endl;
      break;
    }
  }
  
  
  if (light == 2) {
    cout << sum << endl;
  }
}
