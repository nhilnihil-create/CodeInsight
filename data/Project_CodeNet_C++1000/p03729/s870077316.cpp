#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  string A, B, C;

  cin >> A >> B >> C;

  char alast = A[A.size() - 1];
  char bfirst = B[0];
  char blast = B[B.size() - 1];
  char cfirst = C[0];

  if (alast == bfirst && blast == cfirst) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }



}
