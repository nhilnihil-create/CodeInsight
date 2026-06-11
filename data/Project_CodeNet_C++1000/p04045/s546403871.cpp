
#include<bits/stdc++.h>
using namespace std;


int vis [10];

bool check( int n)
{  
     //check n if it have any undesired digit
     //if not return true
	while( n)
	{
	    int x= n%10;
	   if(vis[x]==1) return false ;
		n= n/10;
	}
	return true ;
}


int main()
{
   int n,k ;
   cin>>n>>k;
   
   for( int i=0;i<k;i++)
   {    
        int x;
     	cin>>x;
     	vis[x]=1;  //for marking undesired digit
   	
   	
	}	
	
	for( int i=n ; ; i++)  //look for digit greater than n which have no digit of k
	{
		if( check(i))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	
}