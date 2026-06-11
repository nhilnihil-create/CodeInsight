#include <iostream>
#include<cstdio>
using namespace std;

int main() 
{
	
	int b[4]={4,6,9,11};
	int x,y;
	
    cin>>x>>y;
	
	if(x==2 || y==2)
	{
	    printf("No\n");
	}
	
	else
	{
	    if( (x==b[0] || x==b[1] || x==b[2] || x==b[3]) && ( y==b[0] || y==b[1] || y==b[2] || y==b[3]))
	    {
	        
	        printf("Yes\n");
	    }
	    
	    else if(((x==b[0] ||x==b[1] || x==b[2] || x==b[3]) && (y!=b[0] || y!=b[1] || y!=b[2] || y!=b[3])) || ((x!=b[0] ||x!=b[1] || x!=b[2] || x!=b[3]) && (y==b[0] || y==b[1] || y==b[2] || y==b[3])))
	    
	    {
	        printf("No\n");
	    }
	    
	    else
	    {
	        printf("Yes\n");
	    }
	}
	
	return 0;
}