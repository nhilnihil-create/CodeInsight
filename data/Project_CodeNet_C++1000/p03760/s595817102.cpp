#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string o, e;
  cin >> o >> e;
  for(int i=0; i<o.length()+e.length(); i++){
    if(i%2==0) cout << o.substr(i/2,1);
    else cout << e.substr(i/2,1);
  }
  cout << endl;
  return 0;
}
