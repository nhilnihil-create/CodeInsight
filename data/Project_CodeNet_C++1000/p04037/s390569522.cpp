#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans,j,mx,n,i,a[200001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	/*mx=2e9;
	for(i=1;i<=n;i++){
		if(a[i]>a[i-1])mx=min(mx,a[i]-i);
	}
	ans=mx+n-1;
	if(ans%2==0)puts("Second");
	 else puts("First");*/
	for(i=1;i<=n;i++)if(i>a[i])break;
	i--;
	if((a[i]-i)%2)return puts("First"),0;
	for(j=i+1;a[j]==i;j++);
	j--;
	if((j-i)%2)puts("First");
	 else puts("Second");
}
/*
观察到sg函数0 or 1跟与端点距离有关 
*/