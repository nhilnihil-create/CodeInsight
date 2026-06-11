#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
const int q=1000000007;
int n,f[1000010],s[1000010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	f[0]=1;
	f[1]=n;
	s[0]=1;
	s[1]=n+1;
	for(i=2;i<=n;i++)
	  {
	   f[i]=(f[i-1]+(i>=3?s[i-3]:0)+(L)(n-1)*(n-1)+n-i+1)%q;
	   s[i]=(s[i-1]+f[i])%q;
	  }
	printf("%d\n",f[n]);
	return 0;
}
