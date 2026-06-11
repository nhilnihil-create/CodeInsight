#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,count=0; cin >> N;
  vector<int> A(N);
  for(int i=1; i<=N; i++) {
    cin >> A[i];
    if(A[i]%2!=0) count++;
  }
  if(count%2 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}