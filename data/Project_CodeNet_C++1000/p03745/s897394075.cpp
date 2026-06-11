
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
	 ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin.tie(NULL);
     ll int n;
     cin>>n;
    int a[n],ans=0;
     for(int i=0;i<n;i++)cin>>a[i];
     for(int i=0;i<n;i++)
     {
		while(i+1<n && a[i]==a[i+1]){i++;}
		if(i+1<n && a[i+1]>a[i])
		{
			while(i<n-1 && a[i+1]>=a[i])
			i++;
		}
		else if(i+1<n && a[i+1]<a[i])
		{
			while(i<n-1 && a[i+1]<=a[i] )
			i++;
		}
		ans++;
	}
	cout<<ans<<endl;
			 
}
		 
    
            

