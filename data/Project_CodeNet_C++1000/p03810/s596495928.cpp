#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

int n;
int arr [MAX_N];

bool wins () {
  int codd = 0;

  for (int i = 0; i < n; i++) {
    codd += arr[i] % 2;
  }

  if (n % 2 == 0 && codd % 2 == 1) return true;
  if (n % 2 == 1 && codd % 2 == 0) return true;
  if (n % 2 == 0 && codd % 2 == 0) return false;
  
  if (codd >= 3) return false;
  if (n == 1 && arr[0] == 1) return false;

  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 1) {
      if (arr[i] == 1) return false;
      arr[i]--;
    }
  }

  int gc = 0;
  for (int i = 0; i < n; i++) {
    gc = gcd(gc, arr[i]);
  }
  
  for (int i = 0; i < n; i++) {
    arr[i] /= gc;
  }
  return !wins();
}

int main () {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (wins()) {
    cout << "First" << '\n';
  } else {
    cout << "Second" << '\n';
  }
}
