#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  
  for (int i=0; i<N; i++) {
    cin >> a.at(i);
  }
  
  int b=0, c=0;
  while (1) {
    c++;
    b=a.at(b)-1;
    if (b==1) {
      break;
    }
    if (c>N) {
      c=-1;
      break;
    }
  }
  cout << c << endl;
}