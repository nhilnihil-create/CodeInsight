#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  int N;
  cin >> N;
  int ma = 0;
  int po = 0;
  rep(i, N)
  {
    int a, b;
    cin >> a >> b;
    if (ma < a) {
      ma = a;
      po = b;
    }
  }
  cout << ma + po << endl;
}