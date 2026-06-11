#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=1;
	int mode=0;
	for(int i=1;i<n;i++)
	{
		if(mode==0)
		{
			if(a[i]==a[i-1]) continue;
			if(a[i]>a[i-1])
				mode=1;
			else
				mode=-1;
		}
		else if(mode==1)
		{
			if(a[i]<a[i-1])
			{
				mode=0;
				ans++;
			}
		}
		else
		{
			if(a[i]>a[i-1])
			{
				mode=0;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
