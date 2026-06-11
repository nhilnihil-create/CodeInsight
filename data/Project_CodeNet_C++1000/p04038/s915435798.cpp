#include<bits/stdc++.h>
#define MOD 1000000007
#define MAX 2001
using namespace std;
long long N,K;
long long Inv[MAX*MAX];
long long Dp[MAX][MAX];
long long Factorial[MAX*MAX];
inline long long Quick_Power(long long X,int P)
{
	register long long Return;
	Return=1;
	while(P)
	{
		if(P&1)
		{
			Return=Return*X%MOD;
		}
		X=X*X%MOD;
		P>>=1;
	}
	return Return;
}
inline long long Combination(long long A,long long B)
{
	return Factorial[A]*Inv[B]%MOD*Inv[A-B]%MOD; 
}
int main(void)
{
	register long long i,j;
	cin>>N>>K;
	if(K==1)
	{
		cout<<1<<endl;
		return 0;
	}
	Factorial[0]=1;
	for(i=1;i<=N*K;i++)
	{
		Factorial[i]=Factorial[i-1]*i%MOD;
	}
	Inv[N*K]=Quick_Power(Factorial[N*K],MOD-2);
	for(i=N*K-1;i>=0;i--)
	{
		Inv[i]=Inv[i+1]*(i+1)%MOD;
	}
	Dp[0][0]=1;
	for(i=1;i<=N;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(!j)
			{
				Dp[i][j]=Dp[i-1][j];
				continue;
			}
			Dp[i][j]=Dp[i-1][j]+Dp[i][j-1]*(N-j+1)%MOD*Combination(N*K-i-1-(j-1)*(K-1),K-2)%MOD;
		}
	}
	cout<<Dp[N][N]<<endl;
	return 0;
}