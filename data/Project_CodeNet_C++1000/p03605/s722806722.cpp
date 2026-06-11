#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  string S;
  cin >> S;
  if (S.at(0) == '9' || S.at(1) == '9') {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}