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
string an;
inline void write(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    an+='0'+a%10; 
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
const int N=505;
int n,a[N],ans[N*N];
PI b[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){ans[a[i]=read()]=i; b[i]=mp(a[i],i);}
	sort(&b[1],&b[n+1]);
	int dq=1;
	for(int i=1;i<=n;i++){
		int t=b[i].second;
		for(int j=1;j<t;j++){
			while(ans[dq])if(ans[dq++]==t){puts("No"); return 0;}
			ans[dq++]=t;
		}
	}
	dq=n*n;
	for(int i=n;i;i--){
		int t=b[i].second;
		for(int j=t+1;j<=n;j++){
			while(ans[dq])if(ans[dq--]==t){puts("No"); return 0;}
			ans[dq--]=t;
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;i++){
		write(ans[i]); an+=' ';
	}
	cout<<an;
}