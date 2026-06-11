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
  string o;
  string e;

  cin >> o >> e;

  for (int i = 0; i < e.size(); ++i) {
    cout << o.at(i) << e.at(i);
  }

  if (o.size() > e.size()) {
    cout << o.at(o.size()-1);
  }
  cout << endl;
  return 0;
}
