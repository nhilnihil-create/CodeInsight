#include <bits/stdc++.h>
#define FI first
#define SE second
#define VE vector<int>
#define PB push_back
#define PA pair<int,int>
#define MA make_pair
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define POS(i) cout<<(i?"POSSIBLE":"IMPOSSIBLE")<<endl
#define Pos(i) cout<<(i?"Possible":"Impossible")<<endl
#define co(i) cout<<i<<endl
#define fcout cout<<fixed<<setprecision(10)
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;

const int MAX_N=200001;
int par[MAX_N];
int rnk[MAX_N];

void init(int n){
    FOR(i,0,n){
        par[i]=i;
        rnk[i]=0;
    }
}

int find(int x){
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(rnk[x]<rnk[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(rnk[x]==rnk[y]) rnk[x]++;
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

int main(){
	int n,k,l; cin>>n>>k>>l;
	init(n);
	FOR(i,0,k){
		int p,q; cin>>p>>q;
		unite(p-1,q-1);
	}
	int a[MAX_N],b[MAX_N];
	FOR(i,0,n){
		a[i]=find(i);
	}
	init(n);
	FOR(i,0,l){
		int r,s; cin>>r>>s;
		unite(r-1,s-1);
	}
	FOR(i,0,n){
		b[i]=find(i);
	}
	map<PA,int> m;
	FOR(i,0,n){
		PA p=PA(a[i],b[i]);
		auto itr=m.find(p);
		if(itr==m.end())
			m[p]=1;
		else{
			m[p]++;
		}
	}
	FOR(i,0,n){
		int ans=0;
		PA p=PA(a[i],b[i]);
		cout<<m[p]<<" ";
	}
}