#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  string s;
  cin >> s;
  
  int N;
  N = s.size();
  
  int f,e;
  int ans=0;
  
  for(int i=0; i<N; i++){
    if(s.at(i) == 'A'){
      f = i;
      break;
    }  
  }
  
  for(int i=0; i<N; i++){
    if(s.at(i) == 'Z'){
      e = i;
    }
  }

  ans = e - f + 1;
    
  cout << ans << endl;
}