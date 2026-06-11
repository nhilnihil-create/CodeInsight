#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};

int N;
ll L, T;
vector<ll> X;
vector<int> W;

ll calc_count(ll x, ll y, ll l, ll t, int w){
	if(w==2) x+=l;
	if(t*2 < abs(x-y)) return 0;
	ll remain = t*2 - abs(x-y);
	return 1+remain/l;
}

int main(){
	cin >> N >> L >> T;
	X.resize(N);  W.resize(N);
	rep(i,N) cin >> X[i] >> W[i];
//-------------------------------------------
	vector<ll> tmp(N);
	rep(i,N){
		if(W[i]==1) tmp[i] = (X[i]+T)%L;
		else tmp[i] = ((X[i]-T)%L+L)%L;
	}

	ll value = tmp[0];
	sort(tmp.begin(), tmp.end());
	int flag = 0;
	rep(i,N) if(tmp[i]==value) { flag = i; if(W[0]==2) break; }

	ll cnt = 0;
	rep(i,N){
		if(W[0]!=W[i])
			cnt += calc_count(X[0],X[i],L,T,W[0]);
	}

	vector<ll> ans(N);
	if(W[0]==1){
		rep(i,N) ans[(cnt+i)%N] = tmp[(flag+i)%N];
	}else{
		rep(i,N) ans[((-cnt+i)%N+N)%N] = tmp[(flag+i)%N];
	}
//-------------------------------------------
	rep(i,N) cout << ans[i] << endl;
}