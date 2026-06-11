//cwystc <--> 陈威宇是天才  --by cwy
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const double PI=acos(-1);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define Per(i,a,b) for (int i=(a);i>(b);i--)
#define travel_set(it,a) for (set<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_map(it,a) for (map<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_vec(it,a) for (vector<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define p(x) cout << x << endl;
#define def cout << "find" << endl;
#define what_is(x) cout << #x << " is " << x << endl;
template <class T>T sqr(T x){return x*x;}
template <class T>T alex(T x){return (x>0)?x:-x;}
template <class T>void read(T&x){
	x=0;T f=1;char ch=getchar();
	while ((ch<48||ch>57)&&ch!=45)ch=getchar();
	if (ch==45)f=-1,ch=getchar();
	while (ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
	x*=f;
}

//-------------------------------------------------head-------------------------------------------------

#define maxn 100005
int n,a[maxn],b[maxn];
vector<int> E[maxn];
int d[maxn];
void dfs(int x,int l){
	if (d[x]==1){b[x]=a[x];return;}
	Rep(i,0,E[x].size())if (E[x][i]!=l){
		dfs(E[x][i],x);
	}
	ll sm=0;int mx=0;
	Rep(i,0,E[x].size()){
		sm+=b[E[x][i]];mx=max(mx,b[E[x][i]]);
	}
	// cerr << x << " " << sm << " " << mx << endl;
	if (mx>a[x]||a[x]>sm||2*a[x]<sm){puts("NO");exit(0);}
	b[x]=a[x]*2-sm;
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	Rep(i,1,n){
		int x,y;read(x);read(y);
		E[x].pb(y);E[y].pb(x);
		d[x]++;d[y]++;
	}
	if (n==2){
		if (a[1]==a[2])printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	int rot=0;
	rep(i,1,n)if (d[i]!=1){rot=i;break;}
	dfs(rot,0);if (b[rot]==0)puts("YES");else puts("NO");return 0;
}