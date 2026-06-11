#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
const int M=5005;
int n,m,A[M],mxL[M][M],mxR[M][M];
bool dpL[M][M],dpR[M][M];

int main(){
#ifndef ONLINE_JUDGE
//	freopen("jiedai.in","r",stdin);
//	freopen("jiedai.out","w",stdout);
#endif
	rd(n),rd(m);
	for(int i=1;i<=n;i++)rd(A[i]);
	dpL[0][0]=dpR[n+1][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(dpL[i-1][j])dpL[i][j]=1;
			if(dpL[i-1][j]&&j+A[i]<m)dpL[i][j+A[i]]=1;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<m;j++){
			if(dpR[i+1][j])dpR[i][j]=1;
			if(dpR[i+1][j]&&j+A[i]<m)dpR[i][j+A[i]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			mxL[i][j]=mxL[i][j-1];
			mxR[i][j]=mxR[i][j-1];
			if(dpL[i][j])mxL[i][j]=j;
			if(dpR[i][j])mxR[i][j]=j;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=0;j<m;j++)MAX(res,mxL[i-1][j]+mxR[i+1][m-1-j]);
		if(res+A[i]<m)ans++;
	}
	printf("%d\n",ans);
	return (0-0);
}
