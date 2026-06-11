#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  long long mod=pow(10, 9)+7, N, P=1;
  cin >> N;
  for (int i=1; i<=N; i++) {
    P=P*i%mod;
  }
  cout << P << endl;
}
