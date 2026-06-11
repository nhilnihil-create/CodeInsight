#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  set<int> paint;
  rep(i, 3) {
    int num;
    cin >> num;
    paint.insert(num);
  }
  cout << paint.size() << endl;
}