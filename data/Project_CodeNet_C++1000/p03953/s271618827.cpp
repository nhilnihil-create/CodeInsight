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
#define mt make_tuple
typedef tuple<int,int,int,int> tp;
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
signed main(){
	int n;
	cin>>n;
	vi in(n);
	rep(i,n)cin>>in[i];
	ll m,k;
	cin>>m>>k;
	rep(i,n-1)in[n-i-1]-=in[n-i-2];
	vi t(n-1);
	rep(i,n-1)t[i]=i;
	while(m--){
		int a;cin>>a;
		swap(t[a-2],t[a-1]);
	}
	while(k){
		if(k%2){
			vi w=in;
			rep(i,n-1)w[i+1]=in[t[i]+1];
			in=w;
		}
		vi nt(n-1);
		rep(i,n-1)nt[i]=t[t[i]];
		t=nt;
		k/=2;
	}
	rep(i,n-1)in[i+1]+=in[i];
	rep(i,n)cout<<in[i]<<endl;
}





