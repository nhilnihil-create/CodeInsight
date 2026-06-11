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
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
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
const int inf=1<<30;
const ll INF=1ll<<52;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const vi emp;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,-0};
const int DX[8]={-1,-1,-1,0,0,1,1,1},DY[8]={1,0,-1,1,-1,1,0,-1};

void Out(vi a){
	for(int i=0;i<a.size();i++){
		if(i) cout<<' ';
		cout<<a[i];
	}
	cout<<endl;
}

int n,m;
vi a;

int main(){
	cin>>n>>m;
	a=vi(m);
	for(int i=0;i<m;i++) cin>>a[i];
	if(m==1){
		cout<<a[0]<<endl;
		if(a[0]==1) cout<<1<<endl<<1<<endl;
		else cout<<2<<endl<<a[0]-1<<' '<<1<<endl;
	}
	else{
		int num=0;
		for(int i=0;i<m;i++) if(a[i]%2==1) num++;
		if(num>2) cout<<"Impossible"<<endl;
		else{
			bool flag=0;
			for(int i=0;i<m;i++) if(a[i]%2==1){
				if(!flag){
					swap(a[0],a[i]);
					flag=1;
				}
				else swap(a[m-1],a[i]);
			}
			Out(a);
			a[0]--;
			a[m-1]++;
			if(!a[0]) a.erase(a.begin());
			if(!a[m-1]) a.erase(a.end()-1);
			cout<<a.size()<<endl;
			Out(a);
		}
	}
}