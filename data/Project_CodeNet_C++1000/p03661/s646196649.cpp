 #include <bits/stdc++.h>
 #include<vector>
#define ll long long 
using namespace std;

  
int main()
{
       
	   int i,j,n,m;
     
    	cin>>n;
    	vector<ll>ara(n);
    	ll X=0,x=0,ans=INT_MAX;
    	
	 for(i=0;i<n;i++)
     {
     	cin>>ara[i];
     	X+=ara[i];
	 }
	 
	 for(i=0;i<n;i++)
	 {
	 	x+=ara[i];
	 	if(i+1<n)ans=min(ans,abs(X-2*x));
	 	 
	 }
	 
	 cout<<ans<<endl;
	 
    return 0;
}
