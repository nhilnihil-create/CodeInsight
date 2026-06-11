#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

typedef vector<int> perm;
perm pow_perm(perm a,ll k){
	perm ret;
	rep(i,a.size()){
		ret.pb(i);
	}
	for(ll i = 0 ; i < 60 ; i ++){
		if(k%2 == 1){
			perm ret_ = ret;
			rep(i,ret.size()){
				ret[i] = a[ret_[i]];
			}
		}
		perm a_ = a;
		rep(i,a.size()){
			a[i] = a_[a_[i]];
		}
		k /= 2;
	}
	return ret;
}

int main(){
	static ll n;
	static ll x[100010];
	static ll m,k;
	static ll a[100010];
	scanf("%lld",&n);
	rep1(i,n)scanf("%lld",&x[i]);
	scanf("%lld%lld",&m,&k);
	rep1(i,m)scanf("%lld",&a[i]);
	
	perm p;
	rep(i,n-1)p.pb(i);
	rep1(i,m){
		swap(p[a[i]-2],p[a[i]-1]);
	}
	p = pow_perm(p,k);
	ll loc = x[1];
	rep1(i,n){
		printf("%lld\n",loc);
		if(i < n){
			loc += x[p[i-1]+2]-x[p[i-1]+1];
		}
	}
}

