#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
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
typedef tuple<pii,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf=sizeof(Def)==sizeof(long long)?9e18:1e9;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};
int main(){
	int t=-1;
	vi in(15);
	in[0]=1;
	rep(i,14)in[i+1]=in[i]*10;
	rep(i,10){
		cout<<"? "<<in[i+1]<<endl;
		char a;cin>>a;
		if(a!='Y'){
			t=i+1;
			break;
		}
	}
	if(t==-1){
		rep(i,11){
			cout<<"? "<<2*in[i]<<endl;
			char a;cin>>a;
			if(a=='Y'){
				t=i+1;
				break;
			}
		}
		cout<<"! "<<in[t-1]<<endl;
		return 0;
	}
	ll l=in[t-1],r=in[t]-1;
	while(r-l>1){
		ll h=(l+r)/2;
		cout<<"? "<<10*h<<endl;
		char a;cin>>a;
		if(a=='Y')r=h;
		else l=h;
	}
	cout<<"! "<<r<<endl;
}





