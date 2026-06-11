#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
 
  int Ns[N] = {0};
  for( int i = 0; i < M; ++i ){
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    Ns[a] += 1;
    Ns[b] += 1;
  }
  
  for( int i = 0; i < N; ++i ){
    cout << Ns[i] << endl;
  }
}