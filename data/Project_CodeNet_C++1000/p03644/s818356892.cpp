#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int>vi;
#define pb push_back
#define sc(n) scanf("%d",&n)
#define lsc(n) scanf("%lld",&n)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(i=0LL;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define rev1(i,n) for(i=n;i>0;i--)
#define in insert
#define IT ::iterator
#define pr(n) printf("%d\n",n)
#define lpr(n) printf("%lld\n",n);

int main()
{
	int n,ii,ans=0,num=1;
	cin >>n;
	for(ii=2;ii<=n;ii++)
	{
		int aa=0,i=ii;
		while(i%2==0)
		{
			aa++;
			//cout << aa << endl;
			i/=2;
		}
		if(ans<aa)
		{
			ans=aa;
			num=ii;
		}
	}
	
	cout << num;
}
