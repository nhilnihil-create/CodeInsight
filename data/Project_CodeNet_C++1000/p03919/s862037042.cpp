#include <bits/stdc++.h>
using namespace std;

int main() {
  int m,n;
  cin >> m >> n;
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
  
  for(int i=0;i<m*n;i++){
    string s;
    cin >> s;
    
    if(s=="snuke"){
      cout << alphabet.at(i%n) << i/n + 1 << endl;
    }
  }
}