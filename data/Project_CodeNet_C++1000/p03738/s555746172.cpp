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
  string a, b;
  cin >> a >> b;

  if (a.size() > b.size()) {
    cout << "GREATER" << endl;
  } else if (a.size() < b.size()) {
    cout << "LESS" << endl;
  } else {
    for (int i = 0; i < a.size(); ++i) {
      if (a.at(i) > b.at(i)) {
        cout << "GREATER" << endl;
        return 0;
      } else if (a.at(i) < b.at(i)) {
        cout << "LESS" << endl;
	return 0;
      } else {
        continue;
      }
    }

    cout << "EQUAL" << endl;
  }
  return 0;
}
