#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define qwq(x) cerr<<" #"<<#x<<" = "<<x<<endl;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005,T=30000;
int a[N],b[N],p[N],n;

int main(){
	read(n);
	rep(i,1,n){
		read(p[i]);
		a[i]=i*T;
		b[i]=(n+1-i)*T;
	}
	rep(i,1,n)a[p[i]]-=n-i;
	rep(i,1,n)printf("%d ",a[i]);puts("");
	rep(i,1,n)printf("%d ",b[i]);puts("");
	return 0;
}