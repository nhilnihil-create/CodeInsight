#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define lo long long 
#define inf 1000000000
#define md 1000000007
#define pb push_back
#define li 100005
using namespace std;
lo int n,a,b,A[li],sum,A2[li];
bool check(lo int gg){
	lo int tot=gg*b;
	lo int cev=0;
	for(int i=1;i<=n;i++){
		A2[i]=A[i]-tot;
	}
	for(int i=1;i<=n;i++){
		if(A2[i]>0){
			cev+=(A2[i]+(a-b)-1)/(a-b);
		}
	}
	return gg>=cev;
}
int main(){
	scanf("%lld %lld %lld",&n,&a,&b);
	for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
	lo int bas=0,son=1000000000000000/a;
	while(bas<=son){
		lo int mid=(bas+son)/2;
		if(check(mid)) son=mid-1;
		else bas=mid+1;
	}
	printf("%lld\n",bas);
	return 0;
}
