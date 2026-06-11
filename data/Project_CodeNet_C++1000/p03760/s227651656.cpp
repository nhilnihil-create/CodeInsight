#include<iostream>
#include<string>
using namespace std;
int main()
{
  int i;
  string s,t;
  int c[26],m[26];
  cin >> s >> t;
  for(i=0;i<s.size();i++){
    cout << s[i];
    if(i<t.size())
      cout << t[i];
  }
  cout << endl;
  return 0;
}