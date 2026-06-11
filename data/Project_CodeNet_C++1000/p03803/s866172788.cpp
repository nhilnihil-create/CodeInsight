#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B; cin >> A >> B;
  string ans;
  if (A == 1 && B != 1) ans = "Alice";
  else if (B == 1 && A!= 1) ans = "Bob";
  else if (A == B) ans = "Draw";
  else if (A > B) ans = "Alice";
  else ans = "Bob";
  cout << ans <<endl;                   
}