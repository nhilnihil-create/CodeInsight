#include <algorithm>
#include <iostream>
#include <cstdio>
const long long MAXN=0x7fffffffffffff;
using namespace std;
int a_min(long long a,long long b){
	return a>b?b:a;
}
int main(){
	int n,a[400000];
		scanf("%d",&n);
	long long sum=0LL; 
	for(int i=1;i<=n;i++){ 
		scanf("%d",&a[i]);
		sum+=a[i]; 
	} 
	long long snu=0LL; 
 	long long rac; 
	long long ans=MAXN;
	for(int i=1;i<n;i++){ 
  		snu+=a[i]; 
  		rac= sum-snu;
   		ans = min(ans,abs(rac-snu)); 
   } 
	printf("%lld",ans); 
	return 0;
}