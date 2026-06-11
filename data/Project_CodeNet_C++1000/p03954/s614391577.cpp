#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(l,r,i) for(int i=l;i>=r;i--)
#define jdg(x) (P[x]>=t)
//若某个数大于等于t,为1;否则为0
//因此随着t增大0越多 
using namespace std;

typedef long long LL;
const int INF =2147483647;
int qread(){
	int w=1,c,ret;
	while((c=getchar())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =2e5+3;
int P[MAXN],n,p=0,k=1;
bool chk(int t){
//	printf("%d ",t);up(1,n*2-1,i) printf("%d ",jdg(i)); puts("");
	up(1,n-1,i){
		if(jdg(n-i+1)==jdg(n-i)) return jdg(n-i+1);
		if(jdg(n+i-1)==jdg(n+i)) return jdg(n+i-1);
	}
	return jdg(1);
}
int calc(){
	while(k){
		if(chk(p+k)) p+=k,k<<=1;
		else k>>=1;
	}
	return p;
}
int main(){
	n=qread();
	up(1,2*n-1,i) P[i]=qread();
	printf("%d\n",calc());
	return 0;
}
