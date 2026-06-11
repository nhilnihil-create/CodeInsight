#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define pb push_back
typedef double db;
typedef long long ll;
typedef pair<int,int> P;
const int MAXN=2e5+10;
int n,a[MAXN],t[MAXN],res;

bool check(int x)
{
	for(int i=1;i<=2*n-1;i++)
		if(a[i]>=x) t[i]=1;
		else t[i]=0;
	for(int l=n-1,r=n+1;l>=1;l--,r++)
		if(t[l]==t[l+1]) return t[l];
		else if(t[r]==t[r-1]) return t[r];
	return (n&1)?t[n]:t[n]^1;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",&a[i]);
	int l=1,r=2*n-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d",r);
	return 0;
}