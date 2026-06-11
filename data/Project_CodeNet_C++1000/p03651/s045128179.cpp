#include <iostream>

using namespace std;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  int n, k;
  cin >> n >> k;

  int gc = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    gc = gcd(gc, arr[i]);
    mx = max(mx, arr[i]);
  }

  if (k > mx || k % gc != 0) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << "POSSIBLE" << endl;
  }
}
