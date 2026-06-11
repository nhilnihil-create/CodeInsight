#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  copy_n(istream_iterator<string>(cin), H, C.begin());
  for (auto& s : C) {
    cout << s << endl;
    cout << s << endl;
  }
  return 0;
}
