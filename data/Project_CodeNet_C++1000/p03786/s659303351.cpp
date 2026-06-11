#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<long long> a;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  a.resize(N);
  vector<long long> indices(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    indices[i] = i;
  }

  sort(a.begin(), a.end());

  long long ret = 0;
  long long sum = 0;
  for (int i = 0; i < N; ++i) {
    if (i == 0) {
      sum += a[i];
      ret = 1;
    } else {
      if (a[i] > 2 * sum) {
        sum += a[i];
        N -= ret;
      } else {
        sum += a[i];
        ++ret;
      }
    }
  }

  cout << N << endl;

  return 0;
}