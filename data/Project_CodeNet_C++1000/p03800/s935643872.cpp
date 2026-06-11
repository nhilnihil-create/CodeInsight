#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <sstream>
#include <string.h>
#include <bitset>
#include <stack>

using namespace std;
typedef long long ll;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<string> vec = {"SS", "SW", "WS", "WW"};
  for (int i = 0; i < 4; i++) {
    string w = vec[i];
    for (int j = 1; j < N; j++) {
      if (S[j] == 'o') {
        if (w[j] == 'S') {
          w += (w[j - 1] == 'S' ? 'S' : 'W');
        } else {
          w += (w[j - 1] == 'S' ? 'W' : 'S');
        }
      } else {
        if (w[j] == 'S') {
          w += (w[j - 1] == 'S' ? 'W' : 'S');
        } else {
          w += (w[j - 1] == 'S' ? 'S' : 'W');
        }
      }
    }
    if (w[0] != w[N]) {
      continue;
    }
    if (S[0] == 'o') {
      if (w[0] == 'S') {
        if(w[N-1] != w[1]) {
          continue;
        }
      } else {
        if (w[N-1] == w[1]) {
          continue;
        }
      }
    } else {
      if (w[0] == 'S') {
        if(w[N-1] == w[1]) {
          continue;
        }
      } else {
        if (w[N-1] != w[1]) {
          continue;
        }
      }
    }
    for (int j = 0; j < N; j++) {
      cout << w[j];
    }
    cout << endl;
    return 0;
  }
  cout << "-1" << endl;
  return 0;
}
