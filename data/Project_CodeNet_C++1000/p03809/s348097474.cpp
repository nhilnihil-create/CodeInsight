// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
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
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef ll Def;
//typedef ll Def;
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
#define mt make_tuple
typedef tuple<int,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n;
vi in,used;
vvi G;
bool h=true;
ll dfs(int a){
	used[a]=true;
	vi t;
	rep(i,G[a].size()){
		int to=G[a][i];
		if(used[to])continue;
		t.pb(dfs(to));
	}
	if(!t.size())return in[a];
	ll sum=0,ma=0;
	rep(i,t.size()){
		sum+=t[i];
		ma=max(ma,t[i]);
	}
	ll w=in[a];
	if(sum-ma>=ma){
		if(sum<w||w*2<sum)h=false;
		else{
			ll W=sum-w;
			in[a]-=W;
			w-=W;
		}
	}else{
		if(sum<w)h=false;
		else{
			ll W=sum-w;
			W=min(W,sum-ma);
			w-=W;
			in[a]-=W;
//			cout<<in[a]<<" "<<sum-2*W<<endl;
			if(in[a]!=sum-2*W||W<0||in[a]<0)h=false;
		}
	}
//	cout<<" "<<a<<" "<<w<<endl;
	return w;
}
int main(){
	cin>>n;
	in=used=vi(n);
	G=vvi(n);
	rep(i,n)cin>>in[i];
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	ll out=dfs(0);
	int T=G[0].size();
	if((T==1&&out==in[0]||T!=1&&out==0)&&h)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

