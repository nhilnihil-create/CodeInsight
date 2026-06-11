#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define G() Cr=getchar()
int Xr;char Cr;
inline int rd(){   //读入优化
	Xr=0,G();
	while(Cr<'0'||Cr>'9')G();
	while(Cr>='0'&&Cr<='9')Xr=(Xr<<3)+(Xr<<1)+Cr-'0',G();
	return Xr;
}
#define MAX_N 100002
int n,va[MAX_N];
int L,q,l,r,ans;
int lg[20],dp[MAX_N][20]; 
int main(){
	n=rd();
	for(int i=1;i<=n;i++)va[i]=rd();
	L=rd();
	lg[0]=1;
	for(int i=1;i<=16;i++)lg[i]=lg[i-1]<<1; // 预处理 2^i
	
	int t=0;
	for(int i=1;i<=n;i++){
		while(va[t+1]-va[i]<=L&&t<n)t++;
		dp[i][0]=t;
	}
	
	for(int k=1;k<=16;k++){
		for(int i=1;i<=n;i++){
			dp[i][k]=dp[ dp[i][k-1] ][k-1];
		}
	}
	
	q=rd();
	while(q--){
		l=rd(),r=rd();
		if(l>r)swap(l,r);
		ans=0;
		for(int i=16;i>=0;i--)if(dp[l][i]<r)l=dp[l][i],ans+=lg[i];
		printf("%d\n",ans+1);
	}
}