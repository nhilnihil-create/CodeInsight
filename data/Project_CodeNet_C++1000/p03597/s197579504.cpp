#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, N;
  cin >> N >> A;
  if (A<=N*N && N<=100) {cout << N*N-A << endl;}
  else {cout << "エラー" << endl;}
}