#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long i,ans=1;

int main(){
	int n;
	cin>>n;
	for(i=1;i<=n;i++)
		ans=ans*i%mod;
	cout<<ans<<endl;
	return 0; 
}