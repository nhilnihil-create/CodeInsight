#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;

  int sum = 0;
  vector<int> s(N);
  for (int i = 0; i < N; ++i) {
    cin >> s[i];
    sum += s[i];
  }
  sort(s.begin(), s.end());

  if (sum % 10 != 0) {
    cout << sum << endl;
    return 0;
  }
  for (int i = 0; i < N; ++i) {
    if ((sum - s[i]) % 10 != 0) {
      cout << sum - s[i] << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}
