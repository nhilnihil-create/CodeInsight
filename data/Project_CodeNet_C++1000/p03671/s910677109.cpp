#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  int p;
  priority_queue<int, vector<int>, greater<int>> P;
  cin >> p;
  P.push(p);
  cin >> p;
  P.push(p);
  cin >> p;
  P.push(p);
  int a, b;
  a = P.top();
  P.pop();
  b = P.top();
  P.pop();
  cout << a + b << endl;
}