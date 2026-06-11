#include<iostream>
#include<cstring>
using namespace std;
const int N=2000005;
int f[N],a[N];
int main()
{
	//freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++)cin >>a[i];
	//for(int i=1;i<=n;i++)cout <<a[i]<<' ';cout <<endl;
	f[0]=0,f[1]=1==a[1],f[2]=(a[1]==1||a[2]==2)?1:0;
	for(int i=3;i<=n;i++)
	{
		if(a[i]==i)
			f[i]=f[i-2]+1;
		else f[i]=f[i-1];
	}
	cout <<f[n]<<endl;
	//for(int i=1;i<=n;i++)cout <<f[i]<<' ';
	return 0;
}