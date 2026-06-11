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
	int n,k,x,y;
	cin>>n>>k>>x>>y;
	int s=0;
	int k2;

   
    if(n>=k)
    {
    
	  k2= n-k;	
      k=k*x;
      k2=k2*y;
      s=s+k+k2;
     
    }
    
    
    else
    {
    	
    	s=s+(n*x);
    	
    	
	}
    
    cout<<s<<endl;
	
	return 0;
	
}
