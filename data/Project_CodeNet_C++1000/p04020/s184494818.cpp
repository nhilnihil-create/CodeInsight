#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
using namespace std;
int N;
ll f[1010100][2];
int Num[1100000],val[1010000],A[1010000];

int main(){
	cin>>N;
	for(rint i=1;i<=N;++i) cin>>A[i],val[i]=i;
	for(rint i=0;i<=N;++i) f[i][0]=f[i][1]=-1e18;
	f[0][0]=0;
	for(rint i=0;i<N;++i) {
		if(A[i+1]>=2) {
			f[i+1][1]=max(f[i+1][1],f[i][1]+1+(A[i+1]-2)/2);
		}
		if(A[i+1]>=1) {
			f[i+1][0]=max(f[i+1][0],f[i][1]+(A[i+1]-1)/2);
			f[i+1][1]=max(f[i+1][1],f[i][0]+1+(A[i+1]-1)/2);
		}
		f[i+1][0]=max(f[i+1][0],f[i][0]+A[i+1]/2);
	}
	cout<<f[N][0];
	return 0;
}