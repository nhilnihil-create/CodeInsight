#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int M;

  cin >> N >> M;

  vector<int> a(M);
  vector<int> b(M);

  for (int i = 0; i < M; i++){
    cin >> a.at(i) >> b.at(i);
  }

  vector<int> count(N);
  for (int i = 0; i < M; i++){
    count.at(a.at(i)-1)++;
    count.at(b.at(i)-1)++;
  }

  for (int i = 0; i < N; i++){
    cout << count.at(i) << endl;
  }
}
