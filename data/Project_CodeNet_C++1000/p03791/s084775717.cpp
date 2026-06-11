#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const ll INF = 0x3fffffff;
const ll MOD = 1e9+7;

// n^m%MOD を求める。O( log(m) )
ll modpow(ll n, int m){
	ll ret=1;
	for(int i=1; i<=m; i<<=1, (n*=n)%=MOD){
		if( m&i ) (ret *= n) %= MOD;
	}
	return ret;
}

// 逆元を求める
ll modinv(ll n){
	return modpow( n, MOD-2 );
}

// 階乗を求める。O(1)  準備O( n*log(n) )
// fact[n]     : nの階乗
// fact.inv[n] : nの階乗の逆元
class FACTORIAL{
public:
	vector<ll> fact, inv;
	FACTORIAL(int MAX_NUM): fact(MAX_NUM), inv(MAX_NUM) {
		fact[0] = inv[0] = 1;
		for(ll i=1; i<MAX_NUM; i++){
			fact[i] = (fact[i-1] * i) % MOD;
			inv[i] = modinv( fact[i] );
		}
	}
	const ll& operator [ ] ( const int i ) const {
		return fact[i];
	}
} fact(1000006); // nの最大値を指定


// 組み合わせ(Combinationを求める) O(1)
ll cmb(unsigned int n, unsigned int r){
	if( n < r ) return 0;
	return fact[n] * fact.inv[r] % MOD * fact.inv[n-r] % MOD;
}


int main(){
	//ios_base::sync_with_stdio(0);
	ll N;
	ll x[100005], g[100005]={};

	cin >> N;
	rep(i,N) cin >> x[i];
	ll mx = 0;
	rep(i,N){
		ll m = ( (i-mx)*2+1-x[i] ) / 2;
		//if( i == 1 && x[i] >= 2 ) m = 0;
		chmax<ll>(m, 0);
		//bool f = !chmax( mx, m );
		//g[ max( mx, m ) ]++;
		mx += m;
		g[ mx ]++;
		//cout << i << " " << x[i] << " g[" << max( mx, m ) << "] = " << g[ max( mx, m ) ] << endl;
		if( i>0 && (i-mx)*2 == x[i] ) mx++;
	}

	ll ans = 1;
	rep(i,N){
		//cout << g[i] << endl;
		ans *= g[i];
		ans %= MOD;
		g[i+1] += g[i] - 1;
	}

	cout << ans << endl;

	return 0;
}
