#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> vec(N);
  for (int i; i < M; i++) {
    int a,b;
    cin >> a >> b;
    vec[a-1] += 1;
    vec[b-1] += 1;
  }
  for (int i; i < N; i++) {
    cout << vec[i] << endl;
  }
}