#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,a[N],k1,k2;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(i+1>a[i+1]){
			k1=a[i]-i,k2=0;
			for(int j=i+1;j<=n;j++)
				if(a[j]==i) k2++;
			break;
		}
	if(k1&1||k2&1) puts("First");
	else puts("Second");
	return 0;
}