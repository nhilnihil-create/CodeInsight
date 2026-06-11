#include <iostream>
#include <set>

using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> S;
  while (cin >> N) {
    if (!S.insert(N).second) S.erase(N);
  }
  cout << S.size() << endl;
}
