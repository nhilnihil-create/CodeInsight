#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  long long sum = n * 2 + m;

  long long ans;
  if(sum / 2 > m)
    ans = m / 2;
  else
    ans = sum / 4;

  cout << ans << endl;
}
