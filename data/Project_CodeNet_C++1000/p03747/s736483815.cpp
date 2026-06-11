#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
//#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

const double PI = acos(-1);
const double EPS = 1e-9;

const int MX = 100005;
const int MM = 1000000007;

ll N, L, T;
ll X[MX*2], W[MX*2];
ll ans[MX*2];

ll norm(ll x){ return (x%L+L) % L; }
ll dist(ll x, ll y){
	if( x == y ) return L;
	return norm(y-x);
}

ll go(ll t){
	int ch = 0;
	for(int i = 0; i < N; i++){
		if( W[0] != W[i] ) ch = 1;
	}
	if( ch == 0 ) return norm(X[0] + (W[0] == 1?t : -t));

	queue<ll> Q[3];
	ll cur = X[0], dir = W[0], tm = 0;
	for(int i = 1; i <= N-1; i++){
		if( W[i] == 2 ) Q[2].push(X[i]);
	}
	for(int i = N-1; i >= 1; i--){
		if( W[i] == 1 ) Q[1].push(X[i]);
	}
	while(t > tm){
		if( dir == 1 ){
			ll p = Q[2].front(); Q[2].pop();
			ll c = norm(p - tm), dt = dist(cur, c) / 2;
			tm += dt;
			p = norm(c - dt);
			cur = norm(cur + dt);
			
			Q[1].push(p - tm);
		}
		else{
			ll p = Q[1].front(); Q[1].pop();
			ll c = norm(p + tm), dt = dist(c, cur) / 2;
			tm += dt;
			p = norm(c + dt);
			cur = norm(cur - dt);

			Q[2].push(p + tm);
		}
		dir = 3-dir;
	}
	if( dir == 2 ) cur = norm(cur-tm+t);
	if( dir == 1 ) cur = norm(cur+tm-t);
	return cur;
}

int main()
{
	scanf("%lld%lld%lld", &N, &L, &T);
	for(int i = 0; i < N; i++) scanf("%lld%lld", X+i, W+i), X[i] *= 4;
	L *= 4; T *= 4;
	T--;

	ll x = go(L);
	ll nxt = 0;
	for(int i = 0; i < N; i++) if( x == X[i] ) nxt = i;

	ll st = (ll)(N-nxt) * (T/L) % N;
	ll y = go(T%L);

	for(int i = 0; i < N; i++){
		if( W[i] == 1 ) X[i] = ((ll)X[i] + T%L) % L;
		else X[i] = ((ll)X[i] - T%L + L) % L;
	}
	sort(X, X+N); 
	for(int i = 0; i < N; i++) if( X[i] == y ) nxt = i;

	for(int i = 0; i < N; i++){
		ans[(st+i)%N] = X[(nxt+i)%N];
	}
	for(int i = 0; i < N; i++){
		if( ans[i]%4 == 1 ) ans[i] = norm(ans[i]-1);
		else ans[i] = norm(ans[i]+1);
		printf("%lld\n", ans[i] / 4);
	}
}
