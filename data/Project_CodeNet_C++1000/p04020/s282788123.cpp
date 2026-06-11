#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int a[N];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll ans=0;
	int last=0,num=0;
	for(int i=1;i<=n;i++){
		/*if(num&&a[i])ans++,a[i]--;
		ans=ans+1ll*a[i]/2;
		if(a[i]%2)num=1;*/
		ans+=a[i]/2;
		a[i]%=2;
		if(a[i]&&a[i+1])a[i]--,a[i+1]--,ans++;
		
	}
	cout<<ans<<endl;
}