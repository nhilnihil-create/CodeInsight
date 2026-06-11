#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  char c ='a';
  sort(S.begin(), S.end());
 
  for(int i=0; i<S.size(); i++) {
    if(S.at(i) == c) c +=1;
  }
  
  if(c > 'z') cout << "None" << endl;
  else cout << c << endl;
}