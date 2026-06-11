#include <bits/stdc++.h>
using namespace std;

int main() {
   string N ;
  cin >> N ;
 bool ans = false ;
  if(N[0]=='9' || N[1]=='9') ans = true ;
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
