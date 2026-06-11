#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  map<int, int> m;
  for (int i = 0; i < N; ++i)
    ++m[A[i]];
  if (m.size() % 2 == 1)
    cout << m.size() << endl;
  else
    cout << m.size() - 1 << endl;
}
