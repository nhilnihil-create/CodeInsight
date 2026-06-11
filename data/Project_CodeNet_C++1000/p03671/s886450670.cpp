#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> m(3);

  rep(i, 3) {
    cin >> m[i];
  }

  std::sort(m.begin(), m.end());

  cout << m[0] + m[1] << endl;


  return 0;
}
