#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
  ll x,y;
  cin >> x >> y;
  printf((abs(x-y) <= 1) ? "Brown\n" : "Alice\n");
}
