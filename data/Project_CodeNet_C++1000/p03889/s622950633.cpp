#include<iostream>
#include<algorithm>
using namespace std;
string s,t;
main()
{
  cin>>s;
  t=s;
  reverse(t.begin(),t.end());
  for(char&c:t)c=c=='b'?'d':c=='d'?'b':c=='p'?'q':'p';
  cout<<(s==t?"Yes":"No")<<endl;
}