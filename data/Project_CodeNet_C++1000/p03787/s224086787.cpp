#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<52;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const vi emp;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,-0};
const int DX[8]={-1,-1,-1,0,1,1,1,0},DY[8]={1,0,-1,-1,-1,0,1,1};

class Union_Find_Tree{
	public:
	vi Par,Rank,Size;
	Union_Find_Tree(int n){
		Par=Rank=vi(n);
		Size=vi(n,1);
		for(int i=0;i<n;i++) Par[i]=i;
	}
	int Find_Par(int x){
		if(Par[x]==x) return x;
		return Par[x]=Find_Par(Par[x]);
	}
	int Find_Size(int x){
		return Size[Find_Par(x)];
	}
	bool Unite(int x,int y){
		x=Find_Par(x);
		y=Find_Par(y);
		if(x==y) return 0;
		if(Rank[x]<Rank[y]){
			Par[x]=y;
			Size[y]+=Size[x];
		}
		else{
			Par[y]=x;
			Size[x]+=Size[y];
			if(Rank[x]==Rank[y]) Rank[x]++;
		}
		return 1;
	}
	bool Same(int x,int y){
		return Find_Par(x)==Find_Par(y);
	}
};

int n,m;

int main(){
	cin>>n>>m;
	Union_Find_Tree uft1(n),uft2(n*2);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		uft1.Unite(u,v);
		uft2.Unite(u,v+n);
		uft2.Unite(v,u+n);
	}
	ll num0=0,num1=0,N=0;
	vi b(n);
	for(int i=0;i<n;i++){
		int p=uft1.Find_Par(i);
		if(!b[p]){
			if(uft1.Find_Size(p)==1){
				N++;
				b[p]--;
			}
			else{
				num0+=(uft2.Same(i,i+n)?1:2);
				num1++;
				b[p]++;
			}
		}
	}
	ll ans=N*n*2-N*N;
	for(int i=0;i<n;i++){
		int p=uft1.Find_Par(i);
		if(b[p]==1){
			b[p]++;
			if(uft2.Same(i,i+n)) ans+=num1;
			else ans+=num0;
		}
	}
	cout<<ans<<endl;
}