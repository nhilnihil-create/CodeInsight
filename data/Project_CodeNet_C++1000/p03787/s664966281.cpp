#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
	return rand()%x;
}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005;
int n,m,flag,vis[N],gu,sum;
vector<int> v[N];
void dfs(int p,int color){
	if(vis[p]==-1)vis[p]=color;
	else {if(vis[p]!=color)flag=1; return;}
	for(unsigned i=0;i<v[p].size();i++)dfs(v[p][i],color^1);
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	memset(vis,-1,sizeof(vis));
	int gu=0,fe=0,er=0;
	for(int i=1;i<=n;i++)if(vis[i]==-1){flag=0; dfs(i,0); if(v[i].size()){if(flag)fe++; else er++;} else gu++;}
	//cout<<gu<<" "<<fe<<" "<<er<<endl;
	cout<<(ll)gu*gu+(ll)gu*(n-gu)*2+(ll)fe*er*2+(ll)er*er*2+(ll)fe*fe<<endl;
}
/*
2 1
2 6
3 4
3 5

(2,3) (1,6) (1,4) (1,5) (
(1,2)-(1连出的点，2连出的点）
*/