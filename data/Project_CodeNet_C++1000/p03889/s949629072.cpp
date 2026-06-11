#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  string s;
  cin>>s;
  string t = s;
  reverse(t.begin(),t.end());
  for(int i = 0; t.size() > i; i++){
    if(t[i] == 'b')t[i] = 'd';
    else if(t[i] == 'd')t[i] = 'b';
    else if(t[i] == 'q')t[i] = 'p';
    else t[i] = 'q';
  }
  if(s==t)cout << "Yes" << endl;
  else cout << "No" << endl;
}