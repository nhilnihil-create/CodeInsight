#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[110000];
  int count = 0;
  
  for (int i=0;i<N;i++) {
    cin >> A[i];
    if (A[i]%2 != 0) count++; 
  }
  
  if (count%2 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}