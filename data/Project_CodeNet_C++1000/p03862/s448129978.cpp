 #include<bits/stdc++.h>
 using namespace std;
 #define ll long long
 


int main()
{
	ll n,m;cin>>n>>m;
	ll a[n+1];
	for(ll i=1;i<=n;i++)cin>>a[i];
	
	if(n==1)
	{
		if(a[1]<=m)cout<<"0\n";
		else
		{
		n=a[1]-(a[1]-m);cout<<n<<endl;
		}
	}
	else
	{
		ll count=0;
		for(int i=2;i<=n;i++)
		{
	      if(a[i]+a[i-1]<=m)continue;
	      else
	      {
	       ll cut=a[i]+a[i-1]-m;
	       if(a[i]>=cut){
	       a[i]=a[i]-cut;
	       count+=cut;continue;}
	       
	       if(a[i]<cut){
	       count+=a[i];
	       cut-=a[i];
	        a[i]=0;

	       if(a[i-1]>=cut){
	       a[i-1]-=cut;
	       count+=cut;}
	       	
	       }
	       
	       
	      }
		}
		cout<<count<<endl;
	}
	
}