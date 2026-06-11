#include<stdio.h>
#define mkp make_pair
#define getbit(a) (1<<(a-1))
#define lowbit(a) ((a)&(-(a)))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define readbit(a,b) ((a>>(b-1))&1)
#define filein(a) freopen(a,"r",stdin)
#define fileout(a) freopen(a,"w",stdout)
#define plp(a,b,c) for(register int a=b;a<=c;a++)
#define rlp(a,b,c) for(register int a=b;a<=c;a++)
//get
inline void get(int &x) {
	static char c = getchar();x = 0;static int fh = 1;
	while(c < '0' || c > '9')fh=(c=='-')?-1:1,c = getchar();
	while(c <= '9' && c >= '0') x = x*10+c-48, c = getchar();
	x=x*fh;
}
inline void get(long long &x) {
	static char c = getchar();x = 0;static int fh = 1;
	while(c < '0' || c > '9')fh=(c=='-')?-1:1,c = getchar();
	while(c <= '9' && c >= '0') x = x*10+c-48, c = getchar();
	x=x*fh;
}
//get
//putll
inline void putll(long long x) {
	if(x==0) {putchar(48);return;}
	if(x<0){putchar('-');x=-x;}
	static int num = 0;static char c[25];
	while(x) c[++num] = (x%10)+48, x /= 10;
	while(num) putchar(c[num--]);
}
//putll
/*
//Gragh
const int maxv=20005;const int maxe=20005;
static int vet[maxe],vis[maxv],head[maxv],next[maxe],edgenum;
static int val[maxe];
//Gragh
//add
inline void add(int u,int v) {
    vet[++edgenum]=v;
    next[edgenum]=head[u];
    head[u]=edgenum;
}
inline void add(int u,int v,int value){
    vet[++edgenum]=v;
    val[edgenum]=value;
    next[edgenum]=head[u];
    head[u]=edgenum;
}
//add
*/
//正文从这里开始，以上都是MTL
char st[100005];
char map[256];
#include<cstring>
int len;
int main(){
	scanf("%s",st);
	len=strlen(st);
	if(len&1){
		puts("No");
		return 0;
	}
	map['d']='b';map['b']='d';map['p']='q';map['q']='p';
	for(register int i=0;i<(len>>1);i++)
		if(map[st[i]]!=st[len-i-1]){
			puts("No");
			return 0;
		}
	puts("Yes");
} 