#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  bool ans = false;
  cin >> A >> B;
  if(A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0)
    ans = true;
  if(ans) cout << "Possible" << "\n";
  else cout << "Impossible" << "\n";
  return 0;
}
