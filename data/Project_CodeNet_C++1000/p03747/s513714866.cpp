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
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

ll n,L,T;
vl a;

int main(){
	cin>>n>>L>>T;
	a=vl(n);
	ll I=0;
	for(int i=0;i<n;i++){
		ll x,t;
		cin>>x>>t;
		if(t==1){
			a[i]=(x+T)%L;
			I=(I-(T+x)/L%n+n)%n;
		}
		else{
			a[i]=(x-T%L+L)%L;
			(I+=(T+L-x-1)/L)%=n;
		}
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++) cout<<a[(n-I+i)%n]<<endl;
}
