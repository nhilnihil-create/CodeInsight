#include<iostream>
using namespace std;
int main(){
  string s;
  bool ans;
  cin >>s;
  ans = (s.size()%2==0)^(s[0]==s[s.size()-1]);
  if(ans)cout <<"Second\n";
  else cout << "First\n";
}
