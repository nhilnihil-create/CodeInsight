#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_map<int, bool> m;
  while (cin >> N) {
    m[N] = !m[N];
  }
  cout << count_if(begin(m), end(m), [](auto &p) { return p.second; }) << endl;
}
