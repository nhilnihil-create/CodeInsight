#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a;
  int S, S1;
  S = 0;
  S1 = 0;
  int OOTJNY;
  OOTJNY = 0;
  b = 0;
  while(b < a){
    cin >> S >> S1;
    b++;
    if(S == S1){
      OOTJNY++;
    }
    else{
      OOTJNY += (S1 - S) + 1;
    }
  }
  cout << OOTJNY << endl;
  
  
}