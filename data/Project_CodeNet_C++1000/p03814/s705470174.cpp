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
  string s;
  cin >> s;

  // problem statement guarantees a finding
  int index_a = -1;
  int index_z = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (s.at(i) == 'A') {
      if (index_a == -1) {
        index_a = i;
      }
    }

    if (s.at(i) == 'Z') {
      index_z = i;
    }
  }

  cout << index_z-index_a+1 << endl;
  return 0;
}
