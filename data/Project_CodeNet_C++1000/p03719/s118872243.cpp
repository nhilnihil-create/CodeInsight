#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  if (A <= C && C <= B) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}