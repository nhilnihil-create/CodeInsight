#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, C;
  cin >> A >> B >> C;
  if(A == B && A == 5 && C == 7)
    cout << "YES" << "\n";
  else if(A == C && A == 5 && B == 7)
    cout << "YES" << "\n";
  else if(B == C && B == 5 && A == 7)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
  return 0;
}
