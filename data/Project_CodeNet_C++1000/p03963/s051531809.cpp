#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K, X = 1;
  cin >> N >> K;
  for (int i = 0; i < N - 1; i++) {X *= K - 1;}
  cout << X * K << endl;
}