#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int v[3];
  cin >> v[0];
  cin >> v[1];
  cin >> v[2];

  sort(v, v + 3);
  if (v[0] == 5 && v[1] == 5 && v[2] == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
