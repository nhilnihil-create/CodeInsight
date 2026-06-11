///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//                       _oo0oo_                         //
//                      o8888888o                        //
//                      88" . "88      ------ hzt1       //
//                      (| -_- |)                        //
//                      0\  =  /0                        //
//                    ___/`---'\___                      //
//                  .' \|     |// '.                     //
//                 / \|||  :  |||// \                    //
//                / _||||| -:- |||||- \                  //
//               |   | \  -  /// |     |                 //
//               | \_|  ''\---/''  |_/ |                 //
//               \  .-\__  '-'  ___/-. /                 //
//             ___'. .'  /--.--\  `. .'___               //
//          ."" '<  `.___\_<|>_/___.' >' "".             //
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |           //
//         \  \ `_.   \_ __\ /__ _/   .-` /  /           //
//     =====`-.____`.___ \_____/___.-`___.-'=====        //
//                       `=---='                         //
//                                                       //
//                                                       //
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~       //
//                                                       //
//                 God-He Bless All.                     //
//           This Code Will Never Explode.               //
//                                                       //
//                                                       //
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define rep(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;i++)
#define dwn(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;i--)
using namespace std;
const int Size=1<<16;
char buffer[Size],*head,*tail;
inline char Getchar() {
    if(head==tail) {
        int l=fread(buffer,1,Size,stdin);
        tail=(head=buffer)+l;
    }
    if(head==tail) return -1;
    return *head++;
}
inline int read() {
    int x=0,f=1;char c=Getchar();
    for(;!isdigit(c);c=Getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=Getchar()) x=x*10+c-'0';
    return x*f;
}
typedef long long ll;
const int maxn=100010;
int n,A[maxn],f[maxn],first[maxn],nxt[maxn<<1],to[maxn<<1],e;
int deg[maxn],ans;
void AddEdge(int u,int v) {
	deg[u]++;deg[v]++;
	to[++e]=v;nxt[e]=first[u];first[u]=e;
	to[++e]=u;nxt[e]=first[v];first[v]=e;
}
void dfs(int x,int fa) {
	f[x]=deg[x]==1?A[x]:2*A[x];
	for(int i=first[x];i;i=nxt[i]) if(to[i]!=fa) {
		dfs(to[i],x);
		f[x]-=f[to[i]];
		if(f[to[i]]>A[x]) ans=0;
	}
	if(f[x]<0||f[x]>A[x]) ans=0;
}
int main() {
	n=read();
	rep(i,1,n) A[i]=read();
	rep(i,2,n) AddEdge(read(),read());
	ans=1;dfs(1,0);
	if(f[1]) ans=0;
	puts(ans?"YES":"NO");
	return 0;
}
