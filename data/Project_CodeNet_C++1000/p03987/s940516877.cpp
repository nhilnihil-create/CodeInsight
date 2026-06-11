#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<set>
#include<bitset>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define brep(index,num) for(int index=num-1;index>=0;index--)
#define brep1(index,num) for(int index=num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
int main(){
	int N;
	ll a[200001];
	ll za[200001];
	set<ll> pl,mi;
	scan(N);
	rep(i,N){
		scan(a[i]);
		za[a[i]]=i;
	}
	pl.insert(-1);
	pl.insert(N);
	mi.insert(1);
	mi.insert(-N);
	ll ans=0;
	rep1(i,N){
		auto itr=pl.lower_bound(za[i]);
		auto itr2=mi.lower_bound(-za[i]);
		ll migi=(*itr)-za[i];
		ll hidari=(*itr2)+za[i];

		ans+=migi*hidari*i;
		pl.insert(za[i]);
		mi.insert(-za[i]);
	}
	prin(ans);
	return 0;
}
