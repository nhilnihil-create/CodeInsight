#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
const int INF=1e9+100;

int H[maxn],n,A,B;

bool check(long long x){
	long long ret=0;
	for(int i=0;i<n;i++){
		long long sum=B*x;
		if(sum<H[i]){
			long long cha=H[i]-sum;
			if(cha%(A-B)==0) ret+=cha/(A-B);
			else ret+=cha/(A-B)+1;
		}
	}
	if(ret<=x) return true;
	return false; 
}

int main(){
	scanf("%d%d%d",&n,&A,&B);
	for(int i=0;i<n;i++){
		scanf("%d",&H[i]);
	}
	long long low=0,high=INF;
	long long ans=1e10;
	while(low<high){
		long long mid=(low+high)/2;
		if(check(mid)){
			ans=min(ans,mid);
			high=mid;
		}
		else low=mid+1;
	}
	printf("%d",ans);
	return 0;
}