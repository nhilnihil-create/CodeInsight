#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  
  if(min(B,D) - max(A,C) > 0){
   cout << min(B,D) - max(A,C) << endl;
  }
  
  if(min(B,D) - max(A,C) < 1){
   cout << 0 << endl;
  }
}
