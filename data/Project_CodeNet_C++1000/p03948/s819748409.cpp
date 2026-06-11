#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
using namespace std;
int n,T,A[1010000];

int main(){
	cin>>n>>T;
	for(rint i=1;i<=n;++i) cin>>A[i];
	int Min=2e9,Max=0,ans=0;
	for(rint i=1;i<=n;++i) {
		if(A[i]-Min>Max) {
			Max=A[i]-Min;
			ans=1;
		}
		else if(A[i]-Min==Max) ans++;
		Min=min(Min,A[i]);
	}
	cout<<ans<<endl;
	return 0;
}