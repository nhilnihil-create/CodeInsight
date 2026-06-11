#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n, l;
  string ss[110];

  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> ss[i];
  }

  sort(ss, ss + n);

  for (int i = 0; i < n; i++) {
    cout << ss[i];
  }
  cout << endl;

  return 0;
}
