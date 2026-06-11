#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  char A, B;
  cin >> A >> B;
  if (A == 'H') {
    if (B == 'H') {
      cout << 'H' << endl;
    } else {
      cout << 'D' << endl;
    }
  } else if (B == 'H') {
    cout << "D" << endl;
  } else {
    cout << "H" << endl;
  }
}