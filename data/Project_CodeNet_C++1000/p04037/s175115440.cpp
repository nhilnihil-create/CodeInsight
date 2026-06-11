#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,a[100005],ans;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (i=0;i<n&&i<a[i+1];i++);
	bool f=(a[i]-i+1)&1,g=1;
	for (j=i+1;j<=n;j++) if (a[j]>=i) g^=1;
	if (f&&g) cout<<"Second"; else cout<<"First";
	return 0;
}