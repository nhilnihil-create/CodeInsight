#include<bits/stdc++.h>
using namespace std;
char c(const string&s){
  return char(s[0] + 'A' - 'a');
}
int main(){
  string s;
  cin >> s;
  cout << c(s);
  cin >> s;
  cout << c(s);
  cin >> s;
  cout << c(s);
  cout << endl;
}