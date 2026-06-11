#include <bits/stdc++.h>
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
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=998244353;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}

int n;

bool f(vi a){
	int t=0;
	for(int i=0;i<n;i++) t+=(a[i]+1)%2;
	if(t<n-1) return t%2==1;
	if(t%2==1) return 1;
	int g=0;
	for(int i=0;i<n;i++) if(a[i]==1) return 0;
	for(int i=0;i<n;i++) g=gcd(g,a[i]/2*2);
	for(int i=0;i<n;i++) a[i]/=g;
	return !f(a);
}

int main(){
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<(f(a)?"First":"Second")<<endl;
}