#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long N, A, B;
  cin >> N >> A >> B;
  if(A>B) cout << 0 << endl;
  else if(N==1 && A!=B) cout << 0 << endl;
  else cout << (N-2)*(B-A)+1 << endl;
}