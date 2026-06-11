#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int A = S.size();
  cin >> A;
  int B = A - 1;
  cin >> B;
  cout << S[0] << A - 2 << S[B] << endl;
}
