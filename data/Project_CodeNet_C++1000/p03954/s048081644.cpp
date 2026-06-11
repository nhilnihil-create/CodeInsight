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
	int n;
	cin>>n;
	n=2*n-1;
	vi in(n);
	rep(i,n)cin>>in[i];
	int l=1,r=n+1;
	while(r-l>1){
		int h=(l+r)/2;
		vi d(n);
		rep(i,n)if(in[i]>=h)d[i]=1;
		int c=n/2;
		bool H=false;
		if(d[c]==d[c-1]||d[c]==d[c+1])H=d[c];
		else{
			int L=c,R=c;
			while(L&&d[L]!=d[L-1])L--;
			while(R!=n-1&&d[R]!=d[R+1])R++;
			if(L==0&&R==n-1)H=(d[c]+c)%2;
			else if(L==0)H=d[R];
			else if(R==n-1)H=d[L];
			else if(c-L>=R-c)H=d[R];
			else H=d[L];
		}
		if(H)l=h;
		else r=h;
	}
	cout<<l<<endl;
}





