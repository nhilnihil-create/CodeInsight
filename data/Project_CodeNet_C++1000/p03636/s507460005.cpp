#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  string S;
  cin >> S;
  cout << S.at(0) << S.size() - 2 << S.at(S.size() - 1) << endl;
}