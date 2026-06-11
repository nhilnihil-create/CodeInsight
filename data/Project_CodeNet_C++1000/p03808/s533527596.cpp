#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],Z,jum,las,K;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		Z+=i;
		jum+=a[i];
	}
	if(((jum%Z)!=0))
	{
		cout<<"NO\n";
		return 0;
	}
	Z=jum/Z;
	for(i=1;i<=n;i++)
	{
		las=a[i-1];
		if(i==1)
			las=a[n];
		ll X=a[i]-las;
		ll L=0,R=Z,C,H=-1;
		while(L<=R)
		{
			C=(L+R)/2;
			ll tom=C-((Z-C)*(n-1));
		//	cout<<C<<" "<<tom<<" "<<X<<"\n";
			if(tom==X)
			{
				H=C;
				break;
			}
			if(tom<X)
				L=C+1;
			else
				R=C-1;
		}
		//cout<<
	//	cout<<i<<" "<<H<<"\n";
		if(H==-1)
		{
			cout<<"NO\n";
			return 0;
		}
		else
			K+=(Z-H);
	}
	//cout<<K<<"\n";
	if(K==Z)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}