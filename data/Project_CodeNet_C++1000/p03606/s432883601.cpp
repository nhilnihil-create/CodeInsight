#include <bits/stdc++.h>
using namespace std;

int main() {
int i ,N ,l ,r ,s ,j;
  j = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> l >> r;
    s = r - l + 1;
    j = j + s;
  }
  cout << j << endl;
}