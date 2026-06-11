#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
  int i,j,k,a,b,ans;
  string s;
  cin>>s;
  i=0;
  while(s[i]!='A'){i++;}
  k=s.size();
  k--;
  while(s[k]!='Z'){k--;}
  cout<<k-i+1;
  return 0;
}