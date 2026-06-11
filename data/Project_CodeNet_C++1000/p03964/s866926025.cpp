#include <bits/stdc++.h>
using namespace std;


int main()
{
	std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long test=1;
	
	while(test--)
	{
	    long long A,B,a,b,c=0,k,d=0,i,n,j,temp,p,m,ex1,ex2,ex3,ex4,x,y;
	    string s;
	    cin>>n;
	    A=1;B=1;
	    long long ans;
	    for(i=0;i<n;i++)
	    {
	        cin>>a>>b;
	        k=max((A-1)/a,(B-1)/b)+1;
	        A=k*a;B=k*b;
	    }
	    cout<<A+B;
    }
    
}
