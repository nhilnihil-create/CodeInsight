#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct aaa{
	int x,y;
}a[500010];
int n,v[5000010];
bool cmp(aaa a,aaa b){
	return a.x<b.x;
}
bool cmp1(aaa a,aaa b){
	return a.x>b.x;
}
int main(){
	int i,now,la;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		a[i].y=i;v[a[i].x]=i;
	}
	sort(a+1,a+n+1,cmp);
	la=1;
	for(i=1;i<=n;i++){
		now=a[i].y-1;
		while(now){
			while(v[la])la++;
			if(la>a[i].x)return puts("No"),0;
			v[la]=a[i].y;now--;
		}
	}
	la=n*n;
	sort(a+1,a+n+1,cmp1);
	for(i=1;i<=n;i++){
		now=n-a[i].y;
		while(now){
			while(v[la])la--;
			if(la<a[i].x)return puts("No"),0;
			v[la]=a[i].y;now--;
		}
	}
	puts("Yes");
	for(i=1;i<=n*n;i++)printf("%d ",v[i]);
}