#include<iostream>
using namespace std;
int n,a[500][500],f[500][500];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)cin>>a[i][j];
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			bool f=0;
			for(int k=1;k<=n;k++)
				if(i!=k&&j!=k)
				{
					if(a[i][k]+a[k][j]<a[i][j]){cout<<-1<<endl;return 0;}
					if(a[i][k]+a[k][j]==a[i][j]){f=1;break;}
				}
			if(!f)ans+=a[i][j];
		}
	cout<<ans<<endl;
	return 0;
}
