#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;


ll n;
vector<ll> v[100010];//木になる

ll f(int p){
	ll ans=0;
	priority_queue<ll> Q;
	rep(i,v[p].size()){
		Q.push(f(v[p][i]));
	}
	reg(i,1,v[p].size()){
		ll q=Q.top();Q.pop();
		ans=max(ans,i+q);
	}
	return ans;
}

int main(void){
	cin>>n;
	reg(i,2,n){
		ll a;
		cin>>a;
		v[a].push_back(i);//勝った方から負けた方に辺を伸ばす
	}
	cout<<f(1)<<endl;
	return 0;
}