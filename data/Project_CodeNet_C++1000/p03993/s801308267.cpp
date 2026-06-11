#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, cnt=0;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A.at(i);
  rep(i, N) if(A.at(A.at(i)-1)==i+1) cnt++;
  cout << cnt/2 << endl;
}