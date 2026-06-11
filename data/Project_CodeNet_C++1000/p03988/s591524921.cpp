#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],vi[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		++vi[a[i]];
	}
	sort(a+1,a+n+1);

	int k=a[n],res=INT_MAX;
	for(int i=0;i<=k;i++){
		int d=max(k-i,i);
		res=min(res,d);
		if(!vi[d]){
			puts("Impossible");
			return 0;
		}
		else	--vi[d];
	}
	for(int i=1;i<=res;i++)
		if(vi[i]){
			puts("Impossible");
			return 0;
		}
	puts("Possible");
	return 0;
}
