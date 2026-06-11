#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	int t=0;
	for (int i=1;i<=n+1;i++)
		if (a[i]<i){
			t=i-1;
			break;
		}
	int flag=0;	
	if (a[t+1]<a[t]){
		if ((a[t]-t)&1)flag=1;
	}
	if (a[t+1]==t){
		int k=t;
		for (int j=t;j<=n;j++)
			if (a[j]==t)k=j;
		int num=k-t;
		if (num&1)flag=1;	
	}
	if (flag)puts("First");
	else puts("Second");
}