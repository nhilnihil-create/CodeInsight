#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	long long q,h,s,d,n;
	long long cost,min2,min1,min05,min025;
	cin>>q>>h>>s>>d>>n;
	min025=q;
	min05=min(h,2*min025);
	min1=min(s,min05*2);
	min2=min(d,min1*2);

	cost=0;
	while(n>0)
	{
	    if(n>=2)
	    {
	       cost+=(n/2*min2);
	       n=n%2;
	    }
	    else if (n==1)
	    {
	        cost+=min1;
	        n--;
	    }
	}
	cout<<cost<<"\n";
	    
	return 0;
}
