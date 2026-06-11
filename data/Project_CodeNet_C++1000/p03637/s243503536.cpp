#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,a,b=0,c=0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    b += a%4 == 2;
    c += !(a%4);
  }
  if (c >= N/2 || N <= b+2*c) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}