#include <iostream>

using namespace std;

int main() {
  int N, v[100002]{}, ans{}, s;
  cin >> N;
  while (cin >> s) ++v[s];
  s = v[0] + v[1];
  for (int i = 0; i != 100000; ++i) {
    s += v[i + 2];
    ans = ans < s ? s : ans;
    s -= v[i];
  }
  cout << ans << endl;
}
