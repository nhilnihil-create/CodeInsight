#include<bits/stdc++.h>

using namespace std;

int main(){
  string s, t;

  cin>>s;

  t = s;

  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'b') t[i] = 'd';
    else if(s[i] == 'd') t[i] = 'b';

    else if(s[i] == 'p') t[i] = 'q';

    else if(s[i] == 'q') t[i] = 'p';
  }

  reverse(s.begin(), s.end());

  // cout<<t<<endl;

  cout<<(s == t ? "Yes":"No")<<endl;

  return 0;
}
