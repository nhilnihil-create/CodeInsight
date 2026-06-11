#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
*/

ll n,a[100010],sum_all=0,sum=0,l=-1,ans[100010]={};
vector<pair<ll,ll>> v;
priority_queue<ll> Q;

void init(){
	cin>>n;
	reg(i,1,n)cin>>a[i];
	reg(i,1,n){
		Q.push(-a[i]);
		sum+=a[i];
		sum_all+=a[i];
	}
}

int main(void){
	init();
	reg(i,1,n){
		if(l<a[i]){
			while(-Q.top()<a[i]){
				sum -= -Q.top();
				Q.pop();
			}
			v.push_back({i, sum-Q.size()*a[i]});
			l=a[i];
		}
	}
	l=sum_all;
	rep(i,v.size()){
		ans[v[i].first] = l-v[i].second;
		l=v[i].second;
	}
	reg(i,1,n)cout<<ans[i]<<endl;
	return 0;
}