#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,a[maxn],mid,L,R,Ans,N;
bool b[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-f;ch=getchar();}
	while (ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool check(int x){
	int mina=1<<30,minb=1<<30;
	for (int i=1;i<N;i++)
	  if (a[i]<x) b[i]=0;
	  else b[i]=1;
	for (int i=1;i<N-1;i++)
	  if (b[i]==b[i+1]){
	  	if (b[i]) mina=min(mina,min(abs(n-i),abs(n-i-1)));
	  	else minb=min(minb,min(abs(n-i),abs(n-i-1)));
	  }
	if (mina==1<<30&&minb==1<<30) return b[1];
	return mina<minb;
}
int main(){
	n=read();N=n<<1;
	for (int i=1;i<N;i++) a[i]=read();
	L=-1,R=1e8;
	while(R-L>1){
		int mid=L+R>>1;	
		if(check(mid)) L=mid;
		else R=mid;
	}	
	printf("%d",L);
	return 0;
}