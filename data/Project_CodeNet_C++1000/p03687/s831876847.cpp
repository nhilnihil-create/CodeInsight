#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  string s;
  cin >> s;
  int r = s.size() - 1;
  int len = 1;
  int result = 0;
  for (;;) {
    for (char c = 'a'; c <= 'z'; ++c) {
      bool ok = true;
      for (int i = 0; i <= r; ++i) {
        bool found = false;
        for (int j = i; j < i + len; ++j) if (s[j] == c) found = true;
        if (!found) ok = false;
      }
      if (ok) {
        //cerr << len << " " << c << endl;
        cout << result << endl;
        return 0;
      }
    }

    result++;
    len++;
    r--;
  }
  return 0;
}
