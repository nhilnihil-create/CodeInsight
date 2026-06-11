#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  bool init = true;
  int status = 0;
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (vec[i-1] == vec[i]) {
    }
    else if (vec[i-1] < vec[i]) {
      if (status == -1) {
        ++cnt;
        status = 0;
      }
      else {
        status = 1;
      }
    }
    else {
      if (status == 1) {
        ++cnt;
        status = 0;
      }
      else {
        status = -1;
      }
    }
  }

  cout << cnt << endl;
}
