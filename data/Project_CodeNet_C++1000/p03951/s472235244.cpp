#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string s;
  string t;
  cin>>s>>t; 
  
  int ans=0;
  int j=0;
  int flag=0;
  for(int i=0;i<n;i++)
  {
    j=0;
    ans=0;
    if(s[i]==t[j]){
      int p=i;
      ans=0;
      while(p<n && s[p]==t[j])
      {
        ans++;
        p++;
        j++;
      }
      if(p==n)flag=1;
    }
    if(flag)break;
  }
  cout<<(2*n)-ans<<endl;
  return 0;
}