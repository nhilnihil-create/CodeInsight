#include<bits/stdc++.h>
using namespace std;
int n,a[233333],maxx[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)maxx[i]=max(maxx[i-1],a[i]);
	int l=0,ans=0;
	for(int i=n;i>=1;i--)
	{
		while(a[l]<n-i+1)l++;
//		cerr<<l<<' '<<i<<endl;
		if(maxx[i-1]<=n-i+1)
		{
			if((a[i]-(n-i))%2==0||(i-l+1)%2==0)ans=1;
			break;
		}
	}
	if(ans)cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}