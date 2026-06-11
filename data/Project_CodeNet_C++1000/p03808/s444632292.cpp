#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n;
ll s,t,d;
int a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);s+=a[i];}
	t=(n*(n+1ll))>>1;
	if(s%t!=0ll){printf("NO");return 0;}
	s/=t;t=0ll;a[n+1]=a[1];
	for(int i=1;i<=n;i++){
		d=s-(a[i+1]-a[i]);
		if(d%n!=0ll||d<0ll){printf("NO");return 0;}
		t+=d;
	}
	if(t==n*s)printf("YES");else printf("NO");
	return 0;
}