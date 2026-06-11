#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
using namespace std;
ll ans,A[101010];
int n;
int main(){
	cin>>n;
	for(rint i=1;i<=2*n;++i) cin>>A[i];
	sort(A+1,A+2*n+1);
	for(rint i=1;i<=2*n;i+=2) ans+=A[i];
	cout<<ans;  
	return 0;
}