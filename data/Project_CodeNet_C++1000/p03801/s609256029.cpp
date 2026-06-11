#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct aaa{
	ll x,y;
}a[200010];
ll n,i,sum,la,b[200010];
bool cmp(aaa a,aaa b){
	return a.x>b.x;
}
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i].x);
		a[i].y=i;
	}
	sort(a+1,a+n+1,cmp);
	a[n+1].x=0;
	la=a[1].y;sum=1;
	for(i=2;i<=n+1;i++){
		if(a[i].x==a[i-1].x)sum++;
		 else b[la]+=sum*(a[i-1].x-a[i].x),sum++;
		la=min(la,a[i].y);
	}
	for(i=1;i<=n;i++)printf("%lld\n",b[i]);
}