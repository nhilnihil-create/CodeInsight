#include<bits/stdc++.h>
#define title "title"
#define ll long long
#define ull unsigned ll
#define fix(x) fixed<<setprecision(x)
#define pii pair<int,int>
#define vint vector<int>
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define red(i,a,b) for(int i=(a);i>=(b);i--)
#define db double
#define ld long db
using namespace std;
void Freopen(){
	freopen(title".in","r",stdin);
	freopen(title".out","w",stdout);
}
int read(){
	int g=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){g=g*10+ch-'0';ch=getchar();}
	return g*f;
}
const int N=1e2+5;
int n,m,a[N],odd;
signed main(){
	//freopen("a","r",stdin);
	n=read(),m=read();int k=0;
	rep(i,1,m){a[i]=read(),odd+=(a[i]&1);if((a[i]&1)&&!(a[1]&1))swap(a[1],a[i]);else if(a[i]&1)k=i;}if(k)swap(a[m],a[k]);
	if(n==1&&m==1)cout<<1<<'\n'<<1<<'\n'<<1;
	else if(m==1)cout<<n<<'\n'<<2<<'\n'<<1<<' '<<n-1;
	else if(odd>=3)cout<<"Impossible";
	else if(odd<=2){rep(i,1,m)cout<<a[i]<<' ';a[1]--;a[m]++;if(!a[1]){cout<<'\n'<<m-1<<'\n';rep(i,2,m)cout<<a[i]<<' ';}else{cout<<'\n'<<m<<'\n';rep(i,1,m)cout<<a[i]<<' ';}}
	return signed();
}