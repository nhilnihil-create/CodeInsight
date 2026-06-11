#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	string w;
	cin>>w;
	
	int count;
	int i,j;
	for(i=0;i<w.size();i++)
	{
		  count=0;
	     for(j=0;j<w.size();j++)
	     {
	     	 
	     	   if(w[i]==w[j])
	     	   {
	     	   	
	     	       count++;	
	     	   	
			   }
	     	
	     		
		 }
		 
		 
		 if(count%2!=0)
		 {
		 	
		 	break;
		 	
		 }
		
		
	
	}
	
	
	
	
	if(i==w.size())
	{
		
		cout<<"Yes"<<endl;
		
	}
	
	
	else
	{
		
		
		cout<<"No"<<endl;
	}
	

	return 0;
	
}
