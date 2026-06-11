#include<bits/stdc++.h>
using namespace std;

int main(void){
  int X, A, B;
  cin >> X >> A >> B;
  if(A >= B)
    cout << "delicious" << "\n";
  else if(B - A <= X)
    cout << "safe" << "\n";
  else if(B - A > X)
    cout << "dangerous" << "\n";
  return 0;
}
