#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main() {
  int N; cin >> N;
  long a =1,b =1;
  
  for (int i =0; i<N; i++) {
    long T,A; cin >> T >> A;
    long tmpT = a/T, tmpA = b/A;
    long k = max(max((long)1,tmpT), max((long)1,tmpA));
    while (T * k < a || A * k < b) k++;
    a = T * k; b = A * k;
  }
  cout << a + b << endl;
}