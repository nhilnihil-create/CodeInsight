#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> Ball(N,1);
  vector<bool> Red(N,false);
  Red[0] = true;
  
  for (int i = 0; i < M; i++) {
    int F, T;
    cin >> F >> T;
    F--; T--;
    Ball[F] -= 1;
    Ball[T] += 1;
    if (Red[F]) {
      Red[T] = true;
      if (Ball[F] == 0) Red[F] = false;
    }
  }
  
  int c = 0;
  for (int i = 0; i < N; i++) {
    if (Red[i]) c += 1;
  }
  cout << c << endl;
}