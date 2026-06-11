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
#include <complex>
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
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-7;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int n;
vi a;

int main(){
	cin>>n;
	a=vi(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ll res=1;
	int I=0,num=0,b=0;
	while(I<n){
		num++;
		if(b||num>a[I]/2+1){
			I--;
			num--;
			(res*=num)%=mod;
			num--;
			b=-1;
		}
		if(b==0&&a[I]%2==0&&a[I]/2+1==num) b=1;
		else b=0;
		I++;
	}
	for(int i=1;i<=num;i++) (res*=i)%=mod;
	cout<<res<<endl;
}