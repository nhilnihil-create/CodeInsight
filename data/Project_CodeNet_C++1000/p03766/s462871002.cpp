#include<bits/stdc++.h>
#define int long long
#define mod 1000000007ll
using namespace std;

int a[2500000];
signed main(){
	int ans=0;
	int n;cin>>n;
	int sum=1;
	a[1]--;
	for(int i=0;i<n-1;i++){
		sum+=a[i];
		sum%=mod;
		ans+=sum*(n-1)%mod*(n-1)%mod;
		ans%=mod;
		a[i+1]+=sum;
		a[i+2]-=sum;
		a[i+3]+=sum;
		a[i+n+2]-=sum;
		a[i+1]%=mod;
		a[i+2]%=mod;
		a[i+3]%=mod;
		a[i+n+2]%=mod;
		}	
	sum+=a[n-1];
	ans+=sum*n;
	ans%=mod;
	for(int i=n;i<n*2+100;i++){
		sum+=a[i];
		ans+=sum;
		ans%=mod;
		}	
	ans+=mod*100ll;
	ans%=mod;	
	cout<<ans<<endl;	
	}
