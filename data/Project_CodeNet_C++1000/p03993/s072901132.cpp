#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  vector<int> used(N);
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    if (used[i])
      continue;
    if (i + 1 == a[a[i] - 1]) {
      ++ret;
      used[i] = 1;
      used[a[i] - 1] = 1;
    }
  }

  cout << ret << endl;

  return 0;
}