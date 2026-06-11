#include<bits/stdc++.h>
using namespace std;
const int C=4e4;
const int N=2e5;
int p[N],a[N],b[N];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)
	{
		a[i]=C*i;
		b[i]=(n+1-i)*C;
	}
	for (int i=1;i<=n;i++)
		a[p[i]]+=i;
	for (int i=1;i<=n;i++)
	printf("%d ",a[i]);
	printf("\n");
	for (int i=1;i<=n;i++)
	printf("%d ",b[i]);
}
		