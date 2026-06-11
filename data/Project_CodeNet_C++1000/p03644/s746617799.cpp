#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int logN = log2(N);
  int ans = pow(2,logN);
  cout << ans << endl;
  return 0;
}
