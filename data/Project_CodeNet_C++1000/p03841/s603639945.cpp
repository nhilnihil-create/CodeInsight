#include <iostream>
#include <algorithm>
using namespace std;
pair <int,int> a[1000005];
int ans[1000005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].first;
		a[i].second=i;
		ans[a[i].first]=a[i].second;
	}
	sort(a+1,a+n+1);
	int now=1,flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<a[i].second;j++)
		{
			while(ans[now]&&now<=500000) ++now;
			ans[now]=a[i].second;
		}
		if(now>a[i].first)
		{
			flag=1;
		}
	}
	int lst=now+1;
	now=n*n;
	for(int i=n;i>=1;i--)
	{
		for(int j=a[i].second+1;j<=n;j++)
		{
			while(ans[now]&&now>=0) --now;
			ans[now]=a[i].second;
		}
		//cout << i << " " << now << endl;
		if(now<a[i].first)
		{
			flag=1;
		}
	}
	for(int i=1;i<=n*n;i++)
	{
		if(!ans[i])
		{
			flag=1;
		}
	}
	if(flag)
	{
		puts("No");
		return 0;
	}
	puts("Yes"); 
	for(int i=1;i<=n*n;i++)
		cout << ans[i] << " ";
	return 0;
}