#include <bits/stdc++.h>
using namespace std;


int main(){
  int A, B, C;
  cin >> A >> B >> C;

  bool ok = false;
  for (int i = 1; i <= B; i++)
  {
    if (A * i % B == C){
      ok = true;
      break;
    }

  }
    
  cout << (ok ? "YES" : "NO") << endl;
}
