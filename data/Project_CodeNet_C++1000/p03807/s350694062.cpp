#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,sum=0; cin >> N;
  vector<int> A(N);
  for(int i=1; i<=N; i++) {
    cin >> A[i];
    sum+=A[i];
  }
  if(sum%2 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}