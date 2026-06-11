#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;
const int MX=100011;
int n;
struct Edge{int t,nxt;Edge(int _t=0,int _nxt=0):t(_t),nxt(_nxt){}}e[MX<<1];
int hed[MX],ec;
inline void ade(int f,int t){e[++ec]=Edge(t,hed[f]);hed[f]=ec;}
#define FE(k,i) for(int (i)=hed[k];(i);(i)=e[i].nxt)if(e[i].t!=f)
int SG(int k,int f){
	int sum=0;
	FE(k,i)sum^=SG(e[i].t,k)+1;
	return sum;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		static int a,b;scanf("%d%d",&a,&b);
		ade(a,b),ade(b,a);
	}
	puts(SG(1,0)?"Alice":"Bob");
	return 0;
}
