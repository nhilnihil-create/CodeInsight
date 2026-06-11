#include <bits/stdc++.h>
using namespace std;
int n,a[200010],sta[200010],l[200010],r[200010];
long long ans=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	int top=0;
	for (int i=1;i<=n;i++) {
		while (top>0&&a[i]<a[sta[top]]) r[sta[top]]=i,top--;
		sta[++top]=i;
	}
	while (top) r[sta[top]]=n+1,top--;
	top=0;
	for (int i=n;i;i--) {
		while (top>0&&a[i]<a[sta[top]]) l[sta[top]]=i,top--;
		sta[++top]=i;
	}
	while (top) l[sta[top]]=0,top--;
	for (int i=1;i<=n;i++) {
		int ll=l[i]+1,rr=r[i]-1;
		ans+=1LL*a[i]*(i-ll+1)*(rr-i+1);
	}
	cout<<ans;
	return 0;
}