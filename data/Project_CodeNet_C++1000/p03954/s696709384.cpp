#include<cstdio>
using namespace std;
const int N=2e5+5;
int n,A[N],l,r=N;
bool Check(int x){
	for(int i=1;i<n;++i){
		if((A[n-i]>=x)==(A[n-i+1]>=x))return A[n-i]>=x;
		if((A[n+i]>=x)==(A[n+i-1]>=x))return A[n+i]>=x;
	}
	return A[1]>=x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*2-1;++i)scanf("%d",&A[i]);
	while(l+1<r){
		int mid=(l+r)/2;
		if(Check(mid))l=mid;
		else r=mid;
	}
	printf("%d\n",l);
}