#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  string N;
  cin >> N;

  bool contained = false;
  rep(i, N.size()){
    if (N[i] == '9') contained = true;
  }

  if (contained) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
