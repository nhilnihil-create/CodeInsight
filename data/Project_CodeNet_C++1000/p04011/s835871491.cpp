#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;
  cout << min(N, K)*X+max(0, N-K)*Y << endl;
}