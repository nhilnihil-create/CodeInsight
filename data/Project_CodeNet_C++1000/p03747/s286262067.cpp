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
// int dx[]={0,1,0,-1,1,1,-1,-1};
// int dy[]={1,0,-1,0,1,-1,1,-1};//RDLU
int dx[]={-1,-1,0,0,1,1};
int dy[]={-1,0,-1,1,0,1};//RDLU
int main(){
	ll n,l,t;
	cin>>n>>l>>t;
	vp in(n);
	rep(i,n){
		int a,b;
		cin>>a>>b;
		if(b==2)b=-1;
		in[i]={a,b};
	}
	vp pos(n);
	rep(i,n){
		ll dis=t%l;
		pos[i].first=(l+in[i].first+in[i].second*dis)%l;
		pos[i].second=in[i].second;
	}
	pii p=pos[0];
	sort(all(pos));
	bool h=false;
	rep(i,n-1)if(pos[i].first==pos[i+1].first)h=true;
//	rep(i,n)cout<<pos[i].first<<" "<<pos[i].second<<endl;
	ll co=0;
	rep(i,n)if(in[i].second!=in[0].second){
		ll T=t;
		co+=T/l*2;
        T%=l;
		ll dis=in[i].first-in[0].first;
		if(in[0].second==-1)dis=l-dis;
		if(2*T>=dis)co++;
		T-=dis;
		dis=l-dis;
		if(2*T>=dis)co++;
	}
	ll ne=(n+in[0].second*(co%n))%n;
	ll it=lower_bound(all(pos),p)-pos.begin();
	rep(i,n)cout<<pos[(n+it-ne+i)%n].first<<endl;
}





