
#include<iostream>
#include<string>
#define LL long long
#define INF 0x3f3f3f3f
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int N=2e5+100;
using namespace std;
pair<LL,LL>a[N];
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
		if(a[1].first==a[1].second)a[1].first=a[1].second=1;
		for(int i=2;i<=n;i++)
		{
			LL tmp=max((a[i-1].first-1)/a[i].first+1,(a[i-1].second-1)/a[i].second+1);
			a[i].first*=tmp;
			a[i].second*=tmp;
		}
		cout<<a[n].first+a[n].second<<endl;
	}
	return 0;
}
