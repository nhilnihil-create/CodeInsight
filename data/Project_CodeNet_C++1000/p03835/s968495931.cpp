#include <bits/stdc++.h>
using namespace std;

  
int main() {
  int k,s;
  cin >> k>>s;
 
  
  int count=0;
  for(int x=0; x<k+1; x++){
    for(int y=0; y<k+1; y++){
      if (s-x-y>=0 && s-x-y<=k) count++;
    }
  }
  
  cout << count  << endl;
}