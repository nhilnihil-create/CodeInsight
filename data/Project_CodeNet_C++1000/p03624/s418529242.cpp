#include <bits/stdc++.h>
using namespace std;

int main(){

string s;
  cin >> s;
bool app[26];
  for(int i=0;i<26;i++){
    app[i]=false;
  }
for(int i=0;s[i]!='\0';i++){
  app[s[i]-'a'] = true;
}
for(int i=0;i<26;i++){
if(!app[i]){
  printf("%c\n",(char)(i+'a'));
  return 0;
}
}
cout << "None" << endl;
}