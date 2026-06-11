#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x=0;char ch=gc();bool positive=1;
	for(;!isdigit(ch);ch=gc()) if(ch=='-') positive=0;
	for(;isdigit(ch);ch=gc()) x=x*10+ch-'0';
	return positive?x:-x;
}
inline void write(ll x){
	if(x<0){
		x=-x;putchar('-');
	}
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline void writeln(ll x){write(x);puts("");}
inline void writep(ll x){write(x);putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=2e5+5;
int cnt[2],a[N],n;
bool check(int md){
	For(i,0,n-1){
		if(a[n+i]<=md&&a[n+i+1]<=md) return 1;
		if(a[n-i]<=md&&a[n-i-1]<=md) return 1;
		if(a[n+i]>md&&a[n+i+1]>md) return 0;
		if(a[n-i]>md&&a[n-i-1]>md) return 0;
	}
	return a[1]<=md;
}
int main(){
	n=read();
	For(i,1,2*n-1) a[i]=read();
	int l=1,r=2*n-1,mid,ans=0;
	while(l<=r){
		check(mid=l+r>>1)?r=(ans=mid)-1:l=mid+1;
	}
	cout<<ans;
}