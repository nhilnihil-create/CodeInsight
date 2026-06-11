#include<bits/stdc++.h>
#define rint register int
#define ll long long 
using namespace std;
int N,A[101010],tong[110100],Max,Min;
int main(){
	cin>>N;
	Max=-1,Min=10000;
	for(rint i=1;i<=N;++i) cin>>A[i],tong[A[i]]++;
	for(rint i=1;i<=N;++i) {
		Max=max(Max,A[i]);
		Min=min(Min,A[i]);
	}
	if(Max==1) {
		if(N==2) {
			cout<<"Possible";
		}
		else cout<<"Impossible";
		return 0;
	}
	if(tong[Max]<2) {
		cout<<"Impossible\n";
		return 0;
	}
	
	if(Max&1) {
		for(rint i=Min;i<=Max;++i) {
			if(tong[i]<2) {
			cout<<"Impossible\n";
			return 0;}
		}
		if(tong[Min]!=2) {
			cout<<"Impossible\n";
			return 0;
		}
		if(Min!=(Max+1)/2) {
			cout<<"Impossible\n";
			return 0;
		}
	}
	else {
		if(Min!=Max/2) {
			cout<<"Impossible\n";
			return 0;
		}
		for(rint i=Min+1;i<=Max;++i) {
			if(tong[i]<2) {
			cout<<"Impossible\n";
			return 0;}
		}
		if(tong[Min]!=1) {
			cout<<"Impossible\n";
			return 0;
		}
	}
	cout<<"Possible\n";
	return 0;
}