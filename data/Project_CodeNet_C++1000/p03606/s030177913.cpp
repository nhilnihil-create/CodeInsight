#include <bits/stdc++.h>
using namespace std;

int main() { int N;
  cin >> N;
  vector<int> v1(N);
  vector<int> v2(N);
  int s = 0;

  for (int i = 0; i < N; i++) {
    cin >> v1.at(i) >> v2.at(i);
    s = s + v2.at(i) - v1.at(i) + 1;
  }
  cout << s << endl;
}
