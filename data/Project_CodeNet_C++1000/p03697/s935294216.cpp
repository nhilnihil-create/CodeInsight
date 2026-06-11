#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  cin >> A >> B;
  if(A + B >= 10)
    cout << "error" << "\n";
  else
    cout << A + B << "\n";
  return 0;
}
