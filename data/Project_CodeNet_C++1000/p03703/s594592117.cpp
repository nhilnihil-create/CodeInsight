#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,a[200005];
class bit{
	public:
	int s[200005];
	void up(int p,int x){
		while(p<=n){
			s[p]+=x;
			p+=p&-p;
		}
	}
	int get(int p){
		int re=0;
		while(p){
			re=re+s[p];
			p-=p&-p;
		}
		RE re;
	}
	void clear(){
		FILL(s,0);
	}
}tree;
signed main(){
	int k;
	cin>>n>>k;
	FOR(i,1,n){
		cin>>a[i];
		a[i]-=k;
	}
	FOR(i,1,n)a[i]=a[i-1]+a[i];
	V<int> v;
	FOR(i,1,n)v.PB(a[i]);
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	FOR(i,0,n)a[i]=lower_bound(ALL(v),a[i])-v.begin()+1;
	tree.up(a[0],1);
	int t,ans=0;
	FOR(i,1,n){
		ans+=tree.get(a[i]);
		tree.up(a[i],1);
	} 
	cout<<ans;
	RE 0;
}


