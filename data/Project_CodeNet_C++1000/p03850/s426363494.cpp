//@winlere
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;  typedef long long ll;
inline int qr(){
	int ret=0,f=0,c=getchar();
	while(!isdigit(c)) f|=c==45,c=getchar();
	while( isdigit(c)) ret=ret*10+c-48,c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5;
int data[maxn],n;
ll dp[maxn][3];

int main(){
	memset(dp,0xcc,sizeof dp);
	n=qr();
	for(int t=1;t<=n;++t) data[t]=qr();
	dp[0][0]=0;
	for(int t=1;t<=n;++t)
		if(data[t]>0){
			dp[t][0]=max({dp[t][0],dp[t-1][0]+data[t],dp[t-1][1]+data[t],dp[t-1][2]+data[t]});
			dp[t][1]=max({dp[t][1],dp[t-1][1]-data[t],dp[t-1][2]-data[t]});
			dp[t][2]=max({dp[t][2],dp[t-1][2]+data[t]});
		}else{
			data[t]=-data[t];
			dp[t][0]=max({dp[t][0],dp[t-1][0]-data[t],dp[t-1][1]-data[t],dp[t-1][2]-data[t]});
			dp[t][1]=max({dp[t][1],dp[t-1][0]-data[t],dp[t-1][1]+data[t],dp[t-1][2]+data[t]});
			dp[t][2]=max({dp[t][2],dp[t-1][1]+data[t],dp[t-1][2]+data[t]});
		}
	cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
	return 0;	
}

//asdujoifszahikuj