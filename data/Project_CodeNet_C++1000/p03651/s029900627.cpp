#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main () {
  int N, K;
  cin >> N >> K;
  int gc;
  cin >> gc;
  int ma = gc;
  for (int i = 0; i < N - 1; i ++) {
    int a;
    cin >> a;
    if (ma < a) ma = a;
    gc = gcd(gc, a);
    //cout << gc << endl;
  }
  //cout << K % gc << ' ' << ma << endl;
  if (!(K % gc) && K <= ma) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}

