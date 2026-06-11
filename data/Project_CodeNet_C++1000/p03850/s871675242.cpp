
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define LL long long
#define ULL unsigned long long
#define PB push_back
#define MP make_pair
#define VI vector<int>
#define PII pair<int,int>
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define IN freopen("in", "r", stdin);
#define OUT freopen("out", "w", stdout);

const int maxn=100010;

LL a[maxn],per[maxn];
char c[maxn];

int main()
{
	IOS;
	int n;
	cin>>n>>a[0];
	per[0]=a[0];
	LL abssum=a[0];
	LL ans=a[0];
	VI sub;
	for (int j=1;j<n;++j)
	{
		cin>>c[j]>>a[j];
		per[j]=per[j-1]+a[j];
		abssum+=a[j];
		if (c[j]=='+') ans+=a[j];
		else
		{
			ans-=a[j];
			sub.PB(j);
		}
	}
	for (int j=0;j<(int)sub.size()-1;++j)
	{
		int p1=sub[j];
		int p2=sub[j+1];
		LL tis=abssum-(per[p2-1]-per[p1-1])*2;
		ans=max(ans,tis);
		abssum-=a[p1]*2;
	}
	cout<<ans<<endl;
	return 0;
}