#include <iostream>
#include <string>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  int sum = 0;
  rep(i, 0, n) {
    if(i < k) sum += x;
    else sum += y;
  }
  cout << sum << "\n";
}
