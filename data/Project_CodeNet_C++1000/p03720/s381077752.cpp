#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  for (int i = 0; i < M; i++) {cin >> a.at(i) >> b.at(i);}
  for (int i = 0; i < N; i++) {
    int O = 0;
    for (int j = 0; j < M; j++) {
      if (a.at(j) == i + 1) {O++;}
      if (b.at(j) == i + 1) {O++;}
    }
    cout << O << endl;
  }
}