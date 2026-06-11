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
	while ((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if (ch=='-')f=-1,ch=getchar();
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}

//---------------------------------------------------head---------------------------------------------------

#define maxn 300005
#define all 23333333
int n,q;int rot[maxn];
vector<int>ins[maxn];
struct Tree{
	int l,r,c;
}T[all];
int cnt;
int Newnode(int lst){T[++cnt]=T[lst];return cnt;}
void insert(int&rot,int l,int r,int p){
	rot=Newnode(rot);T[rot].c++;if (l==r)return;int mid=(l+r)>>1;
	if (p<=mid)insert(T[rot].l,l,mid,p);else insert(T[rot].r,mid+1,r,p);
}
int query(int rot,int l,int r,int p){
	if (l>=p)return T[rot].c;int mid=(l+r)>>1;
	if (p<=mid)return query(T[rot].l,l,mid,p)+query(T[rot].r,mid+1,r,p);
	else return query(T[rot].r,mid+1,r,p);
}
int solve(int ind){
	int res=0;
	for (int i=ind,lst=0;i<=n;i+=ind,lst+=ind){
		res+=query(rot[i],1,n,i)-query(rot[lst],1,n,i);
	}
	return res;
}
int main(){
	// freopen("E.in","r",stdin);
	// freopen("E.out","w",stdout);
	read(n);read(q);swap(n,q);
	rep(i,1,q){
		int l,r;read(l);read(r);
		ins[l].pb(r);
	}
	rep(i,1,n){
		rot[i]=rot[i-1];
		Rep(k,0,ins[i].size())insert(rot[i],1,n,ins[i][k]);
	}
	rep(i,1,n)printf("%d\n",solve(i));return 0;
}