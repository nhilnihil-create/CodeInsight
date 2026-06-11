#include<bits/stdc++.h>
using namespace std;
int main()
{
  int i;	
  string x,y;
  cin>>x;
  y=x;
  reverse(x.begin(),x.end());
  for(i=0;i<x.size();i++)
    {
      if(x[i]=='b') 
	    x[i]='d';
      else 
	    if(x[i]=='d') 
		  x[i]='b';
      else 
	    if(x[i]=='p') 
		  x[i]='q';
      else 
	    if(x[i]=='q') 
		  x[i]='p';
    }
  if(x==y) 
	cout<<"Yes"<<endl;
  else 
	cout<<"No"<<endl;
  return 0;
}