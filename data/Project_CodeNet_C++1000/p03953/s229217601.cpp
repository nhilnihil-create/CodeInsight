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

/*
ai = 1/2 (2 * ai+1 - ai) + 1/2 (2 * ai-1 - ai) = ai+1 + ai-1 - ai
[ai-1] [ai] [ai+1]  ->  [ai-1] [ai - ai-1] [ai+1 - ai]
[ai-1] [ai+1 + ai-1 - ai] [ai+1]  ->  [ai-1] [ai+1 - ai] [ai - ai-1]
<==> swap(ai+1 - ai , ai - ai-1)
*/

#define maxn 100005
int n,a[maxn],m;ll k;
int l[maxn];
bool vis[maxn];
void solve(int ind){
	vector<pi>_l;_l.clear();vis[ind]=true;_l.pb(mp(ind,a[ind]));
	for (int i=l[ind];i!=ind;i=l[i])vis[i]=true,_l.pb(mp(i,a[i]));
	Rep(i,0,_l.size())a[_l[i].fi]=_l[(k+i)%_l.size()].se;
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	read(m);read(k);
	rep(i,1,n)l[i]=i;
	rep(i,1,m){
		int x;read(x);
		swap(l[x],l[x+1]);
	}
	per(i,n,1)a[i]=a[i]-a[i-1];
	rep(i,1,n)if (!vis[i])solve(i);double res=0.0;
	rep(i,1,n)res+=a[i],printf("%lf\n",res);
	return 0;
}