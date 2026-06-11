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
//#define mt make_tuple
//typedef tuple<int,int,int> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	string s;
	cin>>s;
	int n=s.size();
	vi co(n+2);
	vvi to(n+1,vi(26,inf));
	vi f(26,inf);
	vi used(26);
	int c=0;
	for(int i=n-1;i>=0;i--){
		int now=s[i]-'a';
		co[i]+=co[i+1];
		if(used[now]==0){
			used[now]=1;
			c++;
			if(c==26){
				c=0;
				if(i)co[i-1]++;
				used=vi(26);
			}
		}
		rep(j,26)to[i+1]=f;
		f[now]=i;
	}
//	if(c==26)co[0]++;
	to[0]=f;
	int now=0;
	while(1){
		int mi=inf,mii,h=true;
		rep(i,26)if(to[now][i]!=inf){
			if(mi>co[to[now][i]]){
				mi=co[to[now][i]];
				mii=i;
			}
		}else if(h){
			cout<<(char)(i+'a');h=false;
		}
		if(!h)break;
		cout<<(char)(mii+'a');
		now=to[now][mii]+1;
	}
	cout<<endl;
}







