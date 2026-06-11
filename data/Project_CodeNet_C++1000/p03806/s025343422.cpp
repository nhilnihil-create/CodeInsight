#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define G() Cr=getchar()
int Xr;char Cr;
inline int  rd(){
	Xr=0;G();
	while(Cr<'0'||Cr>'9')G();
	while(Cr>='0'&&Cr<='9')Xr=(Xr<<1)+(Xr<<3)+Cr-'0',G();
	return Xr;
}
int n,Ma,Mb,ans=99999999;
int dp[405][405];
int a[100],b[100],c[100];
int suma[100],sumb[100];
int main(){
	n=rd(),Ma=rd(),Mb=rd();
	for(int i=1;i<=n;i++)
		a[i]=rd(),b[i]=rd(),c[i]=rd(),suma[i]=suma[i-1]+a[i],sumb[i]=sumb[i-1]+b[i];
	
	for(int i=0;i<=suma[n];i++)
		for(int j=0;j<=sumb[n];j++)
			dp[i][j]=99999999;
	dp[0][0]=0;	
	
	for(int k=1;k<=n;k++)
		for(int i=suma[k];i>=a[k];i--)
			for(int j=sumb[k];j>=b[k];j--)
				dp[i][j]=min(dp[i][j],dp[i-a[k]][j-b[k]]+c[k]);		
	
	int aa=Ma,bb=Mb;
	while(Ma<=suma[n]&&Mb<=sumb[n]){
		ans=min(ans,dp[Ma][Mb]);
		Ma+=aa,Mb+=bb;
	}
	
	printf("%d\n", (ans==99999999)?-1:ans );		
}