#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x); i<=(y); i++)
#define per(i,x,y) for (int i=(x); i>=(y); i--)
#define ll long long
#define ld long double
#define inf 1000000000
#define INF 1000000000000000000ll
#define pii pair<int,int>
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sqr(x) ((x)*(x))
#define y1 y1_
#define cmin(x,y) (x)=(y)<(x)?(y):(x)
#define cmax(x,y) (x)=(y)>(x)?(y):(x)
#define mset(x,y) memset((x),(y),sizeof(x))
#define mcpy(x,y) memcpy((x),(y),sizeof(y))
using namespace std;
const ld pi=acos(-1);
const ld eps=1e-8;
//////////////////////// header files ////////////////////////
ll read(){
	char ch=getchar(); ll x=0; int op=1;
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') op=-1;
	for (; isdigit(ch); ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*op;
}
void write(ll a){
	if (a<0) putchar('-'),a=-a;
	if (a>=10) write(a/10); putchar(a%10+'0');
}
////////////////////////// fast i/o //////////////////////////
#ifdef mod
ll ksm(ll x,ll p){
	ll ret=1;
	for (; p; p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
ll get_inv(ll x){
	return ksm(x,mod-2);
}
#else
ll ksm(ll x,ll p){
	ll ret=1;
	for (; p; p>>=1,x=x*x) if (p&1) ret=ret*x;
	return ret;
}
#endif
//////////////////////////// qpow ////////////////////////////
#define N 100005
int n,m,k; ll ans[10];
map<pii,int> Mp;
//#define local
int main(){
#ifdef local
	freopen("test.in","r",stdin); freopen("test.out","w",stdout);
#endif
	n=read(),m=read(),k=read();
	rep (i,1,k){
		int x=read(),y=read();
		rep (i,0,2) rep (j,0,2){
			int x_=x-i,y_=y-j;
			if (x_>=1 && y_>=1 && x_<=n-2 && y_<=m-2) Mp[pii(x_,y_)]++;
		}
	}
	ans[0]=(ll)(n-2)*(m-2);
	for (map<pii,int>::iterator it=Mp.begin(); it!=Mp.end(); it++) ans[it->S]++,ans[0]--;
	rep (i,0,9) cout<<ans[i]<<endl;
	return 0;
}
// sample data:
/*
4 5 8
1 1
1 4
1 5
2 3
3 1
3 2
3 4
4 4

0
0
0
2
4
0
0
0
0
0

======
10 10 20
1 1
1 4
1 9
2 5
3 10
4 2
4 7
5 9
6 4
6 6
6 7
7 1
7 3
7 7
8 1
8 5
8 10
9 2
10 4
10 9

4
26
22
10
2
0
0
0
0
0
*/

// rest:
/*

*/

/*
If you find any bug in my code or solution, please tell me. Thanks so much.
email: 2411280037@qq.com
*/