#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string s;
  cin>>s;
  if(s.size() < 2) {cout<<-1<<' '<<-1; return 0;}
  if(s.size() == 2) {
  	if(s[0] == s[1]) cout<<1<<' '<<2;
    else cout<<-1<<' '<<-1;
    return 0;
  }
  int x=-1,y=-1;
  for (int i=0;i<s.size()-2;i++){
    if (s[i]==s[i+1]||s[i+1]==s[i+2]||s[i+2]==s[i]){
      x=i+1;
      y=i+3;
      break;
    }
  }cout<<x<<' '<<y<<endl;
  return 0;

}