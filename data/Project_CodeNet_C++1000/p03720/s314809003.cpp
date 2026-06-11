#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> vec(N);
  int c;
  for(int i = 0; i < M * 2; i++) {
    cin >> c;
    vec.at(c - 1) += 1;
  }
  for(int i = 0; i < N; i++) {
    cout << vec.at(i) << endl;;
  }
}
