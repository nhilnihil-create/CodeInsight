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
typedef int Def;
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
class SST{
	public:
	int n;
	vi a,b;
	SST(int size){
		n=pow(2,ceil(log2(size)));
		a=b=vi(2*n-1);
	}
	void range_add(int l,int r,int z){//[l,r)+=z
		range_add(0,0,n,l,r,z);
	}
	void range_add(int i,int il,int ir,int l,int r,int z){//[l,r)
		if(l<=il&&ir<=r){
			a[i]+=z;
			b[i]+=z;
		}else if(ir<=l||r<=il){
			
		}else{
			range_add(2*i+1,il,(il+ir)/2,l,r,z);
			range_add(2*i+2,(il+ir)/2,ir,l,r,z);
			b[i]=a[i]+max(b[2*i+1],b[2*i+2]);//max
		}
	}
	int range_max(int l,int r){
		return range_max(0,0,n,l,r);
	}
	int range_max(int i,int il,int ir,int l,int r){
		if(l<=il&&ir<=r){
			return b[i];
		}else if(ir<=l||r<=il){
			return 0;
		}else{
			return a[i]+max(
				range_max(2*i+1,il,(il+ir)/2,l,r),
				range_max(2*i+2,(il+ir)/2,ir,l,r));
		}
	}
	void open(){
		rep(i,a.size())cout<<" "<<a[i];cout<<endl;
		rep(i,b.size())cout<<" "<<b[i];cout<<endl;
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	vvp in(m);
	rep(i,n){
		int a,b;cin>>a>>b;
		in[b-a].pb({a,b});
	}
	int s=n;
	SST sst(m);
	rep(i,m){
		int co=s;
		for(int j=i+1;j<=m;j+=i+1){
			co+=sst.range_max(j-1,j);
		}
		cout<<co<<endl;
		s-=in[i].size();
		rep(j,in[i].size())
			sst.range_add(in[i][j].first-1,in[i][j].second,1);
	}
}





