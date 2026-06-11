#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  long long a[N];
  long long b[N];
  for (int i = 0; i < N; ++i) {
    cin >> a[i] >> b[i];
  }

  long long ret = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (a[i] + ret == 0)
      continue;
    if (a[i] + ret > b[i] && (a[i] + ret) % b[i] != 0) {
      ret += b[i] * ((a[i] + ret) / b[i] + 1) - (a[i] + ret);
    } else if (a[i] + ret < b[i] && b[i] % (a[i] + ret) != 0) {
      ret += b[i] - (a[i] + ret);
    }
  }

  cout << ret << endl;

  return 0;
}