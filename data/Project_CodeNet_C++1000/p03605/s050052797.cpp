#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int bufN;
  cin >> bufN;
  int N= bufN;

  bool contain9= false;
  while(N > 0){
    if(N % 10==9){
      contain9= true;
      break;
    }
    N/= 10;
  }

  string ans= contain9 ? "Yes"
                       : "No";
  cout << ans << endl;
}