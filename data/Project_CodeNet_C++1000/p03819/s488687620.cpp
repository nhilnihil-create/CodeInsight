#include<cstdio>
#include<vector>
const int N=3e5+5;
int n,m,L[N],R[N],B[N],c[N],s;
std::vector<int>X[N],Y[N];
inline void add(int i,int x){for(;i<=m;i+=i&-i)B[i]+=x;}
inline int ask(int i){int x=0;for(;i;i&=i-1)x+=B[i];return x;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",L+i,R+i);
		int l=R[i]-L[i]+1;
		++c[l],X[l].push_back(L[i]),Y[l].push_back(R[i]+1);
	}
	for(int i=m;i;--i)c[i]+=c[i+1];
	for(int i=1;i<=m;++i){
		s=c[i];
		for(int j=i;j<=m;j+=i)s+=ask(j);
		printf("%d\n",s);
		for(int x:X[i])add(x,1);
		for(int x:Y[i])add(x,-1);
	}
	return 0;
}