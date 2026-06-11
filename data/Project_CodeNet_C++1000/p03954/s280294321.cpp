#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 100005
#define maxm 10000005
#define inf 0x7fffffff
#define ll long long

using namespace std;
int N,M,A[maxm],tp[maxm];
bool B[maxm];

inline int read(){
	int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

inline bool check(int x){
	for(int i=1;i<=M;i++) B[i]=(A[i]>=x);
	for(int len=1;len<N;len++){
		if(B[N-len]==B[N-len+1]) return B[N-len];
		if(B[N+len-1]==B[N+len]) return B[N+len];
	}
	return B[1];
}

int main(){
	//freopen("triangle.in","r",stdin);
	//freopen("triangle.out","w",stdout);
	N=read(),M=(N<<1)-1;
	for(int i=1;i<=M;i++) A[i]=read();
	memcpy(tp,A,sizeof(A));
	sort(tp+1,tp+1+M);
	int l=1,r=M,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(tp[mid])) ans=tp[mid],l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
