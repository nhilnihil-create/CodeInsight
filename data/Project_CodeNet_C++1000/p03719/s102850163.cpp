#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, C;
  cin >> A >> B >> C;
  bool ans = false;
  if(A <= C && C <= B)
    ans = true;
  if(ans) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
