#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  cin >> A >> B;
  if(A == B)
    cout << "Draw" << "\n";
  else if(A == 1)
    cout << "Alice" << "\n";
  else if(B == 1)
    cout << "Bob" << "\n";
  else if(A > B)
    cout << "Alice" << "\n";
  else if(A < B)
    cout << "Bob" << "\n";
  return 0;
}
