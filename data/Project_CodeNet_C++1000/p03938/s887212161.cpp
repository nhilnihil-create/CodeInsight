#include<bits/stdc++.h>
#define rint register int 
#define ll long long
using namespace std;
const ll Max=1e9;
int N,P[1010000];
ll Sum[1010000],A[1010000],B[1000000];
int main(){
	cin>>N;
	for(rint i=1;i<=N;++i) cin>>P[i];
	for(rint i=1;i<=N;++i) {
		Sum[P[i]]=Max-N+i;
	}
	A[1]=Max/2;B[1]=Sum[1]-A[1];
	for(rint i=2;i<=N;++i) {
		B[i]=B[i-1]-N;
		A[i]=Sum[i]-B[i];
	}
	for(rint i=1;i<=N;++i) cout<<A[i]<<" ";
	cout<<"\n";
	for(rint i=1;i<=N;++i) cout<<B[i]<<" ";
	cout<<"\n";
	return 0;
}