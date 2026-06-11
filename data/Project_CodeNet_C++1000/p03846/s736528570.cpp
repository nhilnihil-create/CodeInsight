#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

	int n;
	cin>>n;
	int a[n];
	rep(i,n)cin>>a[i];

	sort(a,a+n);
	int flag=0;
	if(n%2==0){
		rep(i,n-1){
			if(a[i]==i+1 && a[i+1]==i+1)i++;
			else {
				flag=1;
				break;
			}
		}
	}
	else {
		if(a[0]!=0)flag=1;
		for(int i=1;i<n-1;i++){
			if(a[i]==i+1 && a[i+1]==i+1)i++;
			else {
				flag=1;
				break;
			}
		}
	}

	if(flag==1){
		cout<<0<<endl;
		return 0;
	}

	int ans=1;
	rep(i,n/2){
		ans*=2;
		ans=ans%mod;
	}
	cout<<ans<<endl;

	return 0;
}
