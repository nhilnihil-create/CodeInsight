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

int main(){
	static ll n,l,t;
	static ll x[100010],w[100010];
	scanf("%lld%lld%lld",&n,&l,&t);
	rep1(i,n)scanf("%lld%lld",&x[i],&w[i]);
	
	static ll y[100010];
	rep1(i,n){
		if(w[i] == 1){
			y[i] = (x[i]+t)%l;
		}
		else {
			y[i] = (x[i]+l-t%l)%l;
		}
	}
	sort(y+1,y+n+1);
	
	ll d = 0;
	rep1(i,n){
		d += y[i]-x[i];
	}
	ll _d = 0;
	rep1(i,n){
		if(w[i] == 1)_d ++;
		else _d --;
	}
	_d *= t;
	int id = (_d-d)/l;
	id %= n;
	while(id < 0)id += n;
	
	rep1(i,n){
		if(i+id > n)printf("%lld\n",y[i+id-n]);
		else printf("%lld\n",y[i+id]);
	}
}