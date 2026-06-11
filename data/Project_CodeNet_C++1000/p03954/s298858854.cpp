#include<bits/stdc++.h>
using namespace std;

int n,a[200100];
bool chk(int x){
	int tag=(a[1]>=x),delta=n*2;
	for(int i=2;i<2*n;++i)
		if((a[i-1]>=x)==(a[i]>=x)){
			int op=(a[i-1]>=x),d=abs(2*i-2*n-1);
			if(d<delta||(d==delta&&!op))tag=op,delta=d;
		}
	return tag;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<2*n;++i)cin>>a[i];
	int l=1,r=2*n-1;
	while(l<r){
		int mid=(l+r+1)/2;
		if(chk(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<'\n';
	return 0;
}