#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  long long k,i=0;
  cin>>k;
  
  while(k)
  {
    if(s[i]=='a'){
      i++;
      if(i==s.size())break;
      continue;}
    if(('z'-s[i]+1LL) <= k)
    {
      	k-=('z'-s[i]+1LL);
        //cout << 'z'-s[i] << endl;
      	s[i]='a';
    }
    i++;
    if(i==s.size())break;
  }

  if(k>0LL)
  {
    k%=26LL;
    s[s.size()-1]+=k;
  }
  
  cout << s << endl;

  
  return 0;
}