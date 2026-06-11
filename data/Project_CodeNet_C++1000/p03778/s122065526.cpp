#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main() {
  int W, a, b;
  cin >> W >> a >> b;
  if (b<a) swap(a,b);
  cout << max(b-a-W,0) << endl;
  return 0;
}
