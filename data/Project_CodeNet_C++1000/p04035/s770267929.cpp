#include<bits/stdc++.h>
#define rint register int
#define ll long long 
using namespace std;
int n,pos,A[1010100],L;
int main(){
	cin>>n>>L;
	for(rint i=1;i<=n;++i) cin>>A[i];
	for(rint i=1;i<=n-1;++i) {
		if(A[i]+A[i+1]>=L) pos=i;
	} 
	if(!pos) cout<<"Impossible"; 
	else {
		cout<<"Possible\n";
		for(rint i=1;i<=pos-1;++i) cout<<i<<endl;
		for(rint i=n-1;i>=pos;--i) cout<<i<<endl;
//		cout<<pos<<endl;
	} 
	return 0;
}