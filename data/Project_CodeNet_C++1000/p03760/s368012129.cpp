#include <iostream>
#include <string>

using namespace std;

int main() {
  string o, e;
  cin >> o >> e;
  size_t es = e.size();
  for (int i = 0; i < es; i++) {
    cout << o[i] << e[i];
  }
  if (es < o.size()) {
    cout << o[es];
  }
  cout << endl;

  return 0;
}
