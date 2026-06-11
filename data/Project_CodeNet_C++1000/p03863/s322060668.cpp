#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

int main(int argc, char* argv[]) {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  /* */
  string s;
  cin >> s;

  if ( (s.length() % 2 == 1) ^ s[0] == s[s.length() - 1]) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  /* */

  return EXIT_SUCCESS;
}
