#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

const int MAX_N=1e5;
int N,M;
ll K;

typedef vector<int> vec;

vec mul(vec a, vec b){
	vec ret(N-1);
	REP(i,N-1){
		ret[i]=a[b[i]];
	}
	return ret;
}

vec pw(vec n,ll m){
	vec ret(N-1);
	REP(i,N-1){
		ret[i]=i;
	}
	if (!m){
		return ret;
	}
	ret=pw(n,m/2);
	ret=mul(ret,ret);
	if (m&1){
		ret=mul(ret,n);
	}
	return ret;
}

int main(){
	ll x0,x1,x;
	cin>>N>>x0;
	x=x0;
	vec dif(N-1);
	REP(i,N-1){
		cin>>x1;
		dif[i]=x1-x0;
		swap(x0,x1);
	}
	cin>>M>>K;
	vec p(N-1);
	REP(i,N-1){
		p[i]=i;
	}
	REP(i,M){
		int a;
		cin>>a;
		swap(p[a-2],p[a-1]);
	}
	p=pw(p,K);
	dif=mul(dif,p);
	cout<<x<<endl;
	x1=x;
	REP(i,N-1){
		x1+=dif[i];
		cout<<x1<<endl;
	}
	return 0;
}