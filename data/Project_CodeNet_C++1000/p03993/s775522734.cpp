#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec) {
    int tmp;
    cin >> tmp;
    v = tmp - 1;
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += vec[vec[i]] == i;
  }

  cout << cnt / 2 << endl;
}
