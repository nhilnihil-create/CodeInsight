#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
	return (rand()<<16|rand())%x;
}
const int N=100005;
#define lowbit(i) i&-i
int n,m,tong[N],c[N];
vector<int> f[N],g[N];
inline int get(int pos){
	int ans=0;
	for(int i=pos;i<=n;i+=lowbit(i))ans+=c[i];
	return ans;
}
inline void change(int pos,int de){
	for(int i=pos;i;i-=lowbit(i))c[i]+=de;
}
int main(){
	m=read(); n=read();
	for(int i=1;i<=m;i++){
		int l=read(),r=read();
		tong[r-l+2]++;
		f[r-l+2].push_back(r); g[r-l+2].push_back(l-1);
	}
	int jb=m;
	for(int i=1;i<=n;i++){
		for(unsigned j=0;j<f[i].size();j++)change(f[i][j],1);
		for(unsigned j=0;j<g[i].size();j++)change(g[i][j],-1);
		jb-=tong[i]; int ans=jb;
		for(int j=i;j<=n;j+=i)ans+=get(j);
		writeln(ans);
	}
}