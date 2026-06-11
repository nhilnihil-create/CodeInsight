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
  int N;
  cin >> N;

  vector<int> a(N);
  int div2 = 0;
  int div4 = 0;
  rep(i, N) {
    cin >> a[i];
    if (a[i] % 4 == 0) div4++;
    else if (a[i] % 2 == 0) div2++;
  }

  if (div2 == N) {
    cout << "Yes" << endl;
    return 0;
  }

  if (div4 == 0) {
    cout << "No" << endl;
    return 0;
  }

  if (div4 * 2 + 1 >= N) {
    cout << "Yes" << endl;
    return 0;
  }

  if (div4 * 2 + div2 >= N) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;

  return 0;
}
