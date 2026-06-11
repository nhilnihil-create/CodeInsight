#include<bits/stdc++.h>
#define int long long
#define Mx 4000000
using namespace std;
const int p=1e9+7;
int n,k;
int f[2010][2010],a[4000010],i_a[4000010];
int calc(int x,int y){ return (((a[y]*i_a[x])%p)*i_a[y-x])%p; }
int power(int x,int y)
{
    int s1=1,s2=x;
    while(y)
	{
        if(y%2)s1*=s2,s1%=p;
        s2*=s2;
        s2%=p;
        y/=2;
    }
    return s1;
}
signed main()
{
    cin>>n>>k;
    if(k==1)
	{
		cout<<1;
		return 0;
	}
    a[0]=1; 
	for(int i=1;i<=Mx;i++)a[i]=(a[i-1]*i)%p;
    i_a[Mx]=power(a[Mx],p-2); 
	for(int i=Mx-1;i>=0;i--)i_a[i]=(i_a[i+1]*(i+1))%p;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
	  for(int j=0;j<=i;j++)
	  {
          f[i][j]=f[i-1][j];
          if(j)f[i][j]+=(f[i][j-1]*(n-j+1)%p*calc(k-2,n-i+(n-j+1)*(k-1)-1)%p)%p;
      }
    cout<<f[n][n];
    return 0;
}