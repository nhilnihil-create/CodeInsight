#include <bits/stdc++.h>
using namespace std;

int main() {
 int K,S, counts = 0, Z = 0;
  cin >> K >> S;
  
  for(int i = 0; i < K+1; i++){
   for(int j = 0; j < K+1; j++){
    Z = S - i - j;
     if(Z < K+1 && Z > -1) counts++;
   }    
  }
  cout << counts << endl;
}
