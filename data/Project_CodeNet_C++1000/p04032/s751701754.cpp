#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >>s;
  int n=s.size();
  int flag=0;
  
  for(int i=0; i<n-1; i++){
    if(s[i]==s[i+1]){
      cout << i+1 << " " << i+2 << endl;
      flag++;
      break;
    }
  }
  
  if(flag==0){
    for(int i=0; i<n-2; i++){
      if(s[i]==s[i+2]){ 
        cout << i+1 << " " << i+3 << endl;
        flag++;
        break;
      }
    }
  }
  
  if(flag==0) cout << -1 << " " << -1 << endl;
}