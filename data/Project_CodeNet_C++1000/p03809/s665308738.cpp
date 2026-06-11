#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define int long long
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return rand()%x;
}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005;
int n,dp[N],a[N],sum;
vector<int> v[N];
void GG(){
	puts("NO"); exit(0);
}
void dfs(int p,int fa){
	if(v[p].size()==1){
		dp[p]=a[p]; return;
	}
	int sum=0,mx=0;
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		dfs(v[p][i],p);
		sum+=dp[v[p][i]]; mx=max(mx,dp[v[p][i]]);
	}
	int x=sum-a[p],y=a[p]-x,gao=mx>sum-mx?sum-mx:4e18;
	if(x<0||y<0||x>gao)GG();
	dp[p]=y;
}
signed main(){
	n=read();
	if(n==2){
		puts(read()==read()?"YES":"NO"); return 0;
	}
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	for(int i=1;i<=n;i++)if(v[i].size()>1){dfs(i,0); if(dp[i])GG(); else puts("YES"); return 0;}
}
/*
x*2+y=sum
x+y=a[i]

*/