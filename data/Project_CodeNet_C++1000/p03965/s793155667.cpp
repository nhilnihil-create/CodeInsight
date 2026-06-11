#include <bits/stdc++.h>
using namespace std;


int main()
{
	std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long test=1;
	
	while(test--)
	{
	    long a,b,c=0,k,d=0,i,n,j,temp,p,m,ex1,ex2,ex3,ex4,x,y;
	    string s;
	    cin>>s;
	    
	    for(i=0;i<s.length();i++)
	    {
	        if(i%2==0)
	        {
	           if(s[i]=='p')
	                c--;
	          
	        }
	        else 
	        {
	           if(s[i]=='g')
	                c++; 
	        }
	    }
	    
	    cout<<(c);
    }
    
}
