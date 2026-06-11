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
int n,m,h,w;
int main(){
	n=read(); m=read(); h=read(); w=read();
	if(n%h==0&&m%w==0){
		puts("No"); return 0;
	}
	puts("Yes");
	if(n%h){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)if(i%h==0){
				write(2*n*(h-1)-1); putchar(' ');
			}else{
				write(-2*n); putchar(' ');
			}
			puts("");
		}
	}else{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)if(j%w==0){
				write(2*m*(w-1)-1); putchar(' ');
			}else{
				write(-2*m); putchar(' ');
			}
			puts("");
		}
	}
}