#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int d[26] = {0};

  string s;
  cin >> s;

  bool ok = true;
  for (char c : s) {
    if (d[c-'a'] != 0) {
      ok = false;
      break;
    } else {
      d[c-'a']++;
    }
  }

  if (ok) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
