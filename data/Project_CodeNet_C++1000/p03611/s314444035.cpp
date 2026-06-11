#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	int a[100000],b[100000];
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
		b[a[i]-1]++;
		b[a[i]+1]++;
	}
	int m=0;
	for(i=0;i<=a[n-1];i++){
		if(m<b[i]) m=b[i];
	}
	printf("%d",m);
	return 0;
}