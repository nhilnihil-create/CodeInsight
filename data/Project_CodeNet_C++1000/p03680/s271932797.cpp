#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  int a = 1;
  
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  
  for (int i = 0; i < N + 1; i++) {
    a = vec.at(a - 1);
    if (a == 2) {
      a = i + 1;
      cout << a << endl;
      a = -1;
      break;
    }
  }    
  if (a != -1) 
    cout << -1 << endl;
}