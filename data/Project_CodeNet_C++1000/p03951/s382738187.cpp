#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  string s, t;
  cin >> s >> t;

  int shared_n = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (i + 1 > t.size())
      break;
    if (s.substr(i) == t.substr(0, s.size() - i))
      shared_n = s.size() - i;
  }

  for (int i = shared_n; i >= 0; --i) {
    if (s.size() + t.size() - i >= N) {
      cout << s.size() + t.size() - i << endl;
      return 0;
    }
  }

  cout << N << endl;

  return 0;
}