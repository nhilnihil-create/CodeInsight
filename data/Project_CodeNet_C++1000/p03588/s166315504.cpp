#include <bits/stdc++.h>
using namespace std;
int INF = 2e9;
int main(){
  int N;
  cin >> N;
  int M = INF;
  for (int i = 0; i < N; i++){
    int A, B;
    cin >> A >> B;
    M = min(M, A + B);
  }
  cout << M;
}