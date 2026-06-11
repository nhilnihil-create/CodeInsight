#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int N;
ll L,T;
vector<ll> X;
vector<int> W;

int main(){
	cin>>N>>L>>T;
	X.resize(N);
	W.resize(N);
	rep(i,N) cin>>X[i]>>W[i];
	vector<ll> tmp(N);
	rep(i,N){
		if(W[i]==1) tmp[i]=(X[i]+T)%L;
		else tmp[i]=((X[i]-T)%L+L)%L;
	}

	sort(all(tmp));
	ll count=0;
	rep(i,N){
		if(W[i]==1) count-=(T-(L-X[i])+L)/L;
		else count+=(T-(X[i]+1)+L)/L;
	}
	count=(count%N+N)%N;
	vector<ll> res(N);
	rep(i,N) res[(i+count)%N]=tmp[i];
	rep(i,N) cout<<res[i]<<endl;
}