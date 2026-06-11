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
int n,a[N];
bool solve(){
	int sum=0,sss=0,flag=0;
	for(int i=1;i<=n;i++)if(a[i]%2==0)sum++; else sss++;
	for(int i=1;i<=n;i++)if(a[i]==1)flag=1; if(flag)return sum&1;
	if(sum&1)return 1; else if(sss>=2)return 0;
	for(int i=1;i<=n;i++)if(a[i]&1)a[i]--;
	int t=0;
	for(int i=1;i<=n;i++)t=__gcd(t,a[i]);
	for(int i=1;i<=n;i++)a[i]/=t;
	return solve()^1;
}
int main(){
	//freopen("std.in","r",stdin); freopen("my.out","w",stdout);
	n=read(); 
	for(int i=1;i<=n;i++)a[i]=read();
	if(n==1){
		if(a[1]==1)puts("Second"); else puts("First"); return 0;
	}
	puts(solve()?"First":"Second");
}
/*
2 1
2 6
3 4
3 5

(2,3) (1,6) (1,4) (1,5) (
(1,2)-(1连出的点，2连出的点）
*/