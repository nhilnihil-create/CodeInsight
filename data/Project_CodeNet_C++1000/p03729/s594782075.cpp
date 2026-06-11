#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  string A, B, C;
  cin >> A >> B >> C;
  if (A.at(A.size() - 1) == B.at(0) && B.at(B.size() - 1) == C.at(0)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}