#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+20;
const int M=2e2+20;
ll v[N];
ll C[M][M]; 
void init()
{
	memset(C,0,sizeof(C));
	C[0][0]=1;
	for(int i=1;i<=50;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}
int main()
{
	int n,A,B;
	init();
	while(cin>>n>>A>>B)
	{
		double ave=0;
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v,v+n);
		reverse(v,v+n);
		for(int i=0;i<A;i++) 
			ave+=v[i];
		ave/=A;
		int num=0,k=0;
		for(int i=0;i<n;i++)
		{
			if(v[i]==v[A-1])
			{
				num++;
				if(i<A)
					k++;
			}
		}	
		ll ans=0; 
		if(k==A)
		{
			for(int i=A;i<=B;i++)
				ans+=C[num][i];
		}
		else
			ans+=C[num][k];

 		cout.precision(20);
 		cout<<fixed<<ave<<endl;
 		cout<<ans<<endl;
	}
	return 0;
}