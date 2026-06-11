#include<cstdio>
int n,k,ni[4000001],jie[4000001],m,dp[2001][2001],mo;
long long mi(long long aa,long long bb)
{
	long long s=1;
	while(bb!=0)
	{
		if((bb%2)==1) s=(s*aa)%mo;
		aa=(aa*aa)%mo;
		bb=bb/2;
	}
	return(s);
}
int main()
{
	scanf("%d%d",&n,&k);
	mo=1000000007;
	m=n*k;
	jie[0]=1;
	for(int i=1;i<=m;i++)jie[i]=(1ll*jie[i-1]*i)%mo;
	ni[m]=mi(jie[m],mo-2);
	for(int i=m;i>=1;i--)ni[i-1]=(1ll*ni[i]*i)%mo;
	dp[0][0]=1;
	if(k==1) printf("1\n");
	else
	{
		k=k-2;
		for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			if(i!=j) dp[i][j+1]=(dp[i][j+1]+1ll*(n-j)*((((1ll*jie[m-j*k-j-1-i]*ni[m-j*k-j-1-k-i])%mo)*((1ll*ni[k]*dp[i][j])%mo))%mo))%mo;
			if(i<n)dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mo;
		}
		printf("%d\n",dp[n][n]); 
	}
} 