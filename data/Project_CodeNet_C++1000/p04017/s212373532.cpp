/*
  mail: mleautomaton@foxmail.com
  author: MLEAutoMaton
  This Code is made by MLEAutoMaton
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define ll long long
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define re register
#define int ll
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
inline int gi(){
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=100010;
int x[N],n,L,nxt[N][20];
signed main(){
	n=gi();
	for(int i=1;i<=n;i++)x[i]=gi();
	L=gi();
	for(int i=1;i<=n;i++){
		int l=i+1,r=n,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(x[mid]-x[i]<=L){ans=mid;l=mid+1;}
			else r=mid-1;
		}
		nxt[i][0]=ans;
	}
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	int q=gi();
	while(q--){
		int a=gi(),b=gi();if(a>b)swap(a,b);
		int ans=0;
		for(int i=18;~i;i--)
			if(nxt[a][i]<b){a=nxt[a][i];ans+=1ll<<i;}
		printf("%lld\n",ans+1);
	}
	return 0;
}