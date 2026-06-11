#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  while(cin >> s){
    int a, b;
    for(a = 0; a < s.size(); a++){
      if(s[a] == 'A') break;
    }
    for(b = s.size() - 1; b >= 0; b--){
      if(s[b] == 'Z') break;
    }
    
    cout << b - a + 1 << endl;
  }
}