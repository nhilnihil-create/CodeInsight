// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) rep(_,v.size())cout<<" "<<v[_];cout<<endl;
#define show2d(v) rep(_,v.size()){rep(__,v[_].size())cout<<" "<<v[_][__];cout<<endl;}cout<<endl;
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef ll Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
// #define mt make_tuple
// typedef tuple<int,int,int> tp;
// typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 1e18+10 : 1e9+10;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};//RDLU
int n,m;
vvi G;
vi used;
ll co1=0,co2=0,co3=0;
bool h;
void dfs(int a,int b){
	used[a]=b;
	rep(i,G[a].size()){
		int to=G[a][i];
		if(used[to]==-1)dfs(to,b^1);
		else if(used[to]==b)h=false;
	}
}
int main(){
	cin>>n>>m;
	G=vvi(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	used=vi(n,-1);
	rep(i,n)if(used[i]==-1){
		if(G[i].size()==0)co1++;
		else{
			h=true;
			dfs(i,0);
			if(h)co2++;
			else co3++;
		}
	}
	cout<<2*co1*n-co1*co1+2*co2*co2+2*co2*co3+co3*co3<<endl;
	
	
	
	/*
	int n,l,t,co=0;
	cin>>n>>l>>t;
	
	vvi in(n,vi(2));
	rep(i,n)rep(j,2)cin>>in[i][j];
	rep(i,n)if(in[i][1]==2)in[i][1]=-1;
	
	vvi g(n,vi(2));
	rep(i,n){
		if(in[0][1]!=in[i][1]){
			ll w=t;
			co+=w/l;
			w%=l;
			ll dis=(l+in[i][0]-in[0][0])%l;
			if(in[0][1]==-1)dis=(l+in[0][0]-in[i][0])%l;
			if(dis<=2*w)co++;
		}
		g[i]={(in[i][0]+t*in[i][1])%l,in[i][1]};
	}
	if(in[0][1]==-1)co=n-1-co%n;
	else co%=n;
	cout<<co<<endl;
	show2d(in);
	show2d(g);
	
	*/
}





