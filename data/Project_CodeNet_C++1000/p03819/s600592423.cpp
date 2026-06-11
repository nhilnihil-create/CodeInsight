#include <iostream>
using namespace std;
int ans[500005],cf[500005],l[500005],r[500005];
const int bl=530;
int main(int argc, char** argv) {
	int n,m,t;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	t=m/bl;
	for(int i=1;i<=n;i++)
		cin >> l[i] >> r[i];
	for(int i=1;i<=n;i++)
	{
		int lst=t;
		for(int j=bl;j>=1;j--)
		{
			int L=(l[i]-1)/j+1,R=r[i]/j;
			L=max(L,lst+1);
			if(R<L) continue;
			++cf[L],--cf[R+1];
			lst=max(lst,R);
		}
	}
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
			ans+=(l[j]-1)/i!=r[j]/i;
		cout << ans << "\n";
	}
	for(int i=t+1;i<=m;i++)
	{
		cf[i]+=cf[i-1];
		cout << cf[i] << "\n";
	}
	return 0;
}
//dlstxdy