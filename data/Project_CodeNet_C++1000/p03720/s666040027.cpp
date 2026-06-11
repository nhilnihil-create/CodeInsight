#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> ab(2 * M);
  vector<int> Ni(N + 1);
  
  for (int i = 0; i < 2 * M; i += 2) {
    int a, b;
    cin >> a >> b;
    ab.at(i) = a;
    ab.at(i + 1) =b;
  }
  
  for (int i = 0; i < 2 * M; ++i) {
    Ni.at(ab.at(i)) += 1;  
  }
  
  for (int i = 1; i < N + 1; ++i) cout << Ni.at(i) << endl;
}