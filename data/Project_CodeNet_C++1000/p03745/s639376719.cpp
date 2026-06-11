#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  vector<long long> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  if (N <= 2) {
    cout << 1 << endl;
    return 0;
  }

  // start until change
  int i;
  long long s = a[0];
  bool increasing;
  for (i = 1; i < N; ++i) {
    if (a[i - 1] == a[i])
      continue;
    if (a[i - 1] < a[i])
      increasing = true;
    else
      increasing = false;
    break;
  }

  int ret = 1;
  --i;
  for (; i < N - 1; ++i) {
    bool change = false;
    if (increasing && a[i] > a[i + 1]) {
      ++ret;
      increasing = false;
      change = true;
    } else if (!increasing && a[i] < a[i + 1]) {
      ++ret;
      increasing = true;
      change = true;
    }

    if (change) {
      for (int j = i + 1; j < N - 1; ++j) {
        if (a[j] == a[j + 1])
          continue;
        if (a[j] < a[j + 1])
          increasing = true;
        else
          increasing = false;
        break;
      }
    }
  }

  cout << ret << endl;

  return 0;
}