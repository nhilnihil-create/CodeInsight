#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long ans = 1;
  for (int i=1;i<=N;i++) {
    ans =ans*i%1000000007;
  }
  cout << ans << endl;
}