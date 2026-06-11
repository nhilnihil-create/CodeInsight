#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define print(n) cout<<n<<endl
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
const int M=200111;
const int inf=1000000007;
const long long INF=1e18;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ddx[8]={1,-1,0,0,1,-1,-1,1},ddy[8]={0,0,1,-1,1,-1,1,-1};


struct UnionFind {
	vector<int> par;
	UnionFind(int n) : par(n, -1) { }

	int root(int x) {
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y); // merge technique
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x) {
		return -par[root(x)];
	}
};

vvl comb(int n, int r) {
	vvl v(n + 1,vl(n + 1, 0));
	for (int i = 0; i < v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (int j = 1; j < v.size(); j++) {
		for (int k = 1; k < j; k++) {
			v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
		}
	}
	return v;
}

void sosu(ll x,bool f[]){
	ll y=x;
	for(ll i=2;i<=sqrt(y);i++){
		if(x%i==0){
			x/=i;
			f[i]=true;
			i--;
		}
	}
}

ll __gcd(ll x,ll y){
	if(x<y)swap(x,y);
	while(1){
		ll tmp=x%y;
		x=y;
		y=tmp;
		if(y==0)break;
	}
	return x;
}

int keta(ll a){
	int ke=1;
	while(a/=10)ke++;
	return ke;
}

int n;
ll a,b,h[M];
bool f(int time){
	ll res=0;
	rep(i,0,n){
		ll tmp=h[i]-time*b;
		if(tmp>0)res+=(tmp+(a-b)-1)/(a-b);
	}
	return (res<=time);
}

int main(){
	cin>>n>>a>>b;
	rep(i,0,n)cin>>h[i];
	int l=0,r=inf;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(f(mid))r=mid;
		else l=mid;
	}
	print(l+1);
}