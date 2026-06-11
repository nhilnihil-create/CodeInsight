#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,mx,x,y,a[500010],now;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)if(a[i]>=i)mx=i;
	x=(a[mx]-mx)%2;
	now=mx;
	while(a[now+1]>=mx)now++,y^=1;
	if(x||y)puts("First");
	 else puts("Second");
}