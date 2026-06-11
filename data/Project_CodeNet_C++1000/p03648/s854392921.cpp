#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,now,a[100];int n=50;
void work(){
	int p=1;
	for (int i=1;i<=n;i++) if (a[i]>a[p]) p=i;
	a[p]-=(n+1);
	for (int i=1;i<=n;i++) a[i]++;
}
int main()
{
	scanf("%lld",&k);
	now=(k+49)/50*50;
	for (int i=1;i<=n;i++) a[i]=(k+49)/50+49;
	while (now>k) work(),now--;
	printf("%d\n",n);
	for (int i=1;i<=n;i++) printf("%lld ",a[i]);
	return 0;
}