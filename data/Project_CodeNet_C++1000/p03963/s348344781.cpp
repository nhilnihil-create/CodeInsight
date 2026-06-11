#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  if(N==1) cout << K << endl;
  else cout << fixed << setprecision(0) << K*pow(K-1,N-1) << endl;
}