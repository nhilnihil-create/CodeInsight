#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int A, B, C;
  cin >> A >> B >> C;
  
  int ans = 0;
  while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0){
    if (A == B && B == C){
      cout << "-1" << endl;
      exit(0);
    }
    
    long long int pA = (B + C) / 2, pB = (A + C) / 2, pC = (A + B) / 2;
    A = pA;
    B = pB;
    C = pC;
    
    ans++;
  }
  
  cout << ans << endl;
}