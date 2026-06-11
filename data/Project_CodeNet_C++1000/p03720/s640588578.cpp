#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, m, a, b;
  cin >> n >> m;

  int count[n] = {0};
  rep(i, m)
  {
    cin >> a >> b;
    count[a-1]++;
    count[b-1]++;
  }

  rep(i, n)
  {
    cout << count[i] << endl;
  }

}
