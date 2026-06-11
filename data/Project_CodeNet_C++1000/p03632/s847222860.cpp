#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int A, B, C, D, N;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> A >> B >> C >> D;
  for (int i = 0; i < 100 + 1; i++) {
    if (A < i && i <= B && C < i && i <= D) {
      N++;
    }
  }
  cout << N << endl;
}