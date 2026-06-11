#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=100005;
int n,a[N],pos;
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(&a[1],&a[n+1]); reverse(&a[1],&a[n+1]);
	for(int i=1;i<=n+1;i++){
		if(a[i+1]<=i){
			pos=i-1; break;
		}
	}
	int t1=a[pos+1]-pos,t2;
	for(int i=1;i<=n;i++)if(a[i+1]<=pos){t2=i-pos; break;}
	t1++; t2++;
	if((t1&1)|(t2&1))puts("First"); else puts("Second");
}