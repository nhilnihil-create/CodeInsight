#include <iostream>
#include <fstream>
#include <cassert>
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
#include <time.h>
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
typedef pair<P,string> pip;
typedef vector<pip> vip;
const int inf=2*1e9+1;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

vl a(11),b(11);

int main(){
	a[0]=1;
	b[0]=10;
	for(int i=1;i<11;i++){
		a[i]=a[i-1]*10;
		b[i]=b[i-1]*10;
	}
	ll l=1e11,r=1e12;
	while(r-l>1){
		ll m=(l+r)/2,n=m;
		char c;
		cout<<"? "<<n<<endl;
		cin>>c;
		for(int i=10;i>=0;i--){
			n/=10;
			ll N=n+1;
			if(c=='Y') b[i]=N;
			else a[i]=N;
		}
		if(c=='Y') r=m;
		else l=m;
	}
	vl res;
	for(int i=0;i<11;i++) if(a[i]<b[i]) res.push_back(a[i]);
	ll A;
	for(int i=1;i<res.size();i++){
		cout<<"? "<<res[i]+1<<endl;
		char c;
		cin>>c;
		if(c=='Y'){
			A=res[i];
			break;
		}
	}
	cout<<"? "<<A-1<<endl;
	char c;
	cin>>c;
	if(c=='Y'^res[0]==1) cout<<"! "<<A<<endl;
	else cout<<"! "<<res[0]<<endl;
}