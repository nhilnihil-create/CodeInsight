#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  int F = 0;
  int T = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a % 4 == 0) {
      F++;
    }
    else if (a % 2 == 0) {
      T++;
    }
  }
  if (T == 0) {
    T = 1;
  }
  if ((F * 2 + T) >= N) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}