#include <iostream>
#include <vector>
using namespace std;

int main() {
  long n;
  cin >> n;
  vector<long> a(n);
  long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  long m = n * (n + 1) / 2;
  if (sum % m) {
    cout << "NO" << endl;
    return 0;
  }

  long num = sum / m;
  long cnt = 0;

  vector<long> d(n);
  for (int i = 0; i < n; i++) {
    d[i] = a[(i + 1) % n] - a[i];
    d[i] -= num;
    if (d[i] == 0) {
      continue;
    }
    if (d[i] < 0 && (-d[i]) % n == 0) {
      cnt += (-d[i]) / n;
      continue;
    }
    cout << "NO" << endl;
    return 0;
  }

  if (cnt == num) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
