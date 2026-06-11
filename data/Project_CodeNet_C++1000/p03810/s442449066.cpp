#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,w[N];
inline int read(){
	int num=0; char g=getchar(); while(g<48||57<g) g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
inline int gcd(int a,int b){
	if(!b) return a; return gcd(b,a%b);
}
inline bool solve(int k){
	if(k&1) return 1;
	if(k+1==n){
		int x=0;
		for(int i=1;i<=n;i++){
			if(w[i]==1) return 0;
			else if(w[i]&1) {w[i]--; break;}
		}
		for(int i=1;i<=n;i++) x=gcd(x,w[i]);
		for(int i=1;i<=n;i++) w[i]/=x;
		k=0; for(int i=1;i<=n;i++) if(!(w[i]&1)) k++;
		return solve(k)^1;
	}
	return 0;
}
int main(){
	n=read(); int x=0; int pos=0,cnt=0;
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=n;i++) if(!(w[i]&1)) cnt++;
	if(solve(cnt)) puts("First"); else puts("Second");
	return 0;
}