#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int c[26]={};
  string s;
  cin >> s;
  for(int i=0; i<s.length(); i++){
    if(c[s[i]-'a']){
      cout << "no" << endl;
      return 0;
    }
    c[s[i]-'a']++;
  }
  cout << "yes" << endl;
  return 0;
}
