#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

int main()
{
  int n;
  cin>>n;
  string s1,s2;
  
  cin>>s1>>s2;
  long ans=0;
  bool currpos,lastpos;
  int i;
  if(s1[0]==s2[0])
  {
    ans=3;
    currpos=0;     //position=0 means vertical
	i=1;  
  }
  else{
    ans=6;
    currpos=1;  //horizontal
    i=2;
  }
  lastpos=currpos;
  while(i<n)
  {
	 if(lastpos==0)
     {
       ans=(ans*2)%M;
       if(s1[i]==s2[i])
       {
         i=i+1;
         currpos=0;
       }
       else{ i=i+2;
            currpos=1;}
       
     }
     else
     {
       if(s1[i]!=s2[i])
       {
         ans=(ans*3)%M;
         i=i+2;
         currpos=1;
         
       }
       else
       {
         i=i+1;
         currpos=0;
       }
       
     }
    
    
    lastpos=currpos;
  }
  
  cout<<ans<<endl;
  
}