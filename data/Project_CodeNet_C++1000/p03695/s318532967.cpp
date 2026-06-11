#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(8);
  int B=0;
  for (int i=0; i<N; i++){
    int a;
    cin >> a;
    if (a<3200) A.at(a/400)++;
    else B++;
  }
  int C=0;
  for (int i=0; i<8; i++){
    if (A.at(i)>0) C++;
  }
  if (C>0) cout << C << " " << B+C << endl;
  else cout << 1 << " " << B << endl;
  return 0;
}