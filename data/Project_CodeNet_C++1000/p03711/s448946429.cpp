#include <iostream>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x, y;
  cin >> x >> y;

  vector<int> a = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};

  cout << (a.at(x) == a.at(y) ? "Yes" : "No") << endl;
}