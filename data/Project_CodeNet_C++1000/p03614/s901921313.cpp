#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,a[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for (int i=1;i<n;i++){
		if (a[i]==i){
			swap(a[i],a[i+1]);
			ans++;
		}
	}
	if (a[n]==n) ans++;
	printf("%d\n",ans);
	return 0;
}