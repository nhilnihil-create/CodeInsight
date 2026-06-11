#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string o, s;
  cin >> o >> s;
  
  int n=o.size();
  int m=s.size();
  for(int j=0; j<n-1; j++){
    cout << o[j] << s[j];
  }
  
  if(n==m){
    cout << o[n-1] << s[n-1];
  }
  else{
    cout << o[n-1];
  }
  
}