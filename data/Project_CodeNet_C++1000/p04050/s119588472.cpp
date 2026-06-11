#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
#define mk make_pair
#define pa pair<int,int>
using namespace std;
int N,M,A[1010010],cnt;
int main(){
	cin>>N>>M;
	for(rint i=1;i<=M;++i) cin>>A[i],cnt+=(A[i]&1);
	if(cnt>2) {
		cout<<"Impossible\n";
		return 0;
	}
	if(N==1) cout<<1<<"\n"<<"1\n1\n",exit(0);
	if(M==1) {
		cout<<N<<"\n2\n"<<N-1<<" "<<1<<endl;
		return 0;
	}
	if(cnt==1) {
		for(rint i=1;i<=M;++i) if(A[i]&1) swap(A[1],A[i]);
		for(rint i=1;i<=M;++i) cout<<A[i]<<" ";
		cout<<endl;
		cout<<M<<endl;
		A[1]++,A[M]--;
//		cout<<A[1]+1<<" ";
		for(rint i=1;i<=M;++i) cout<<A[i]<<" ";
//		cout<<endl; 
		return 0;
	}
	int fl=1;
	for(rint i=1;i<=M;++i) if(A[i]&1) if(fl) swap(A[1],A[i]),fl=0;else swap(A[M],A[i]);
	for(rint i=1;i<=M;++i) cout<<A[i]<<" ";
		cout<<endl;
		A[1]++,A[M]--;
		if(A[M]==0) M--;
		cout<<M<<endl;
	
//		cout<<A[1]+1<<" ";
		for(rint i=1;i<=M;++i) cout<<A[i]<<" ";
//		cout<<endl; 
		return 0;
	return 0;
}