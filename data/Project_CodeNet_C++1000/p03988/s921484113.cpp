#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,a[100010],b[100010];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)b[a[i]]++;
	if(a[n]!=a[n-1])return puts("Impossible"),0;
	for(i=a[n]/2+1;i<=a[n];i++)b[i]-=2;
	if(a[n]%2==0)b[a[n]/2]--;
	for(i=1;i<=(a[n]+1)/2;i++)if(b[i]!=0)return puts("Impossible"),0;
	for(i=(a[n]+1)/2+1;i<=a[n];i++)if(b[i]<0)return puts("Impossible"),0;
	puts("Possible");
}