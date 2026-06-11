#include <iostream>
using namespace std;
int a[200005],n;
bool b[200005];
inline bool pd(int x)
{
	for(int i=1;i<=n*2-1;i++)
	{
		if(a[i]>=x)
			b[i]=1;
		else
			b[i]=0;
	}
	b[0]=b[1];
	if(b[n]==b[n+1]||b[n]==b[n-1])
		return b[n];
	for(int i=n+1;i<=n+n-1;i++)
	{
		if(b[i]==b[i+1])
			return b[i];
		if(b[n+n-i]==b[n+n-i-1])
			return b[n+n-i];
	}
	return b[1];
}
int main(int argc, char** argv) {
	cin >> n;
	for(int i=1;i<=n*2-1;i++)
		cin >> a[i];
	int l=1,r=n*2,ans=0;
	while(l<=r)
	{
		int md=(l+r)/2;
		if(pd(md))
		{
			l=md+1;
			ans=max(ans,md);
		}
		else
			r=md-1;
	}
	cout << ans << endl;
	return 0;
}