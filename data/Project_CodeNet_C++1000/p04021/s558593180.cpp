#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
using namespace std;
int N,A[1010000],idx[1010010],rk[1000010];
inline bool cmp(int i,int j){return A[i]<A[j];}
int main(){
	int n;
	cin>>n;
	int ans=0;
	
	for(rint i=1;i<=n;++i) {
		cin>>A[i];idx[i]=i;
	//	if((i&1)!=(A[i]&1)) 
	}sort(idx+1,idx+n+1,cmp);
	for(rint i=1;i<=n;++i) rk[idx[i]]=i;
	for(rint i=1;i<=n;++i)if((i&1)!=(rk[i]&1)) ans++;
	cout<<ans/2; 
	return 0;
}