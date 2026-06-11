#include<iostream>
using namespace std;

typedef long long int ll;
const int N = 5e5;
ll MOD = 1e9+7;
ll fat[N];

ll m(ll x, ll y){
	return (x * y) % MOD;
}

void build(){
	fat[0] = 1;
	for(ll i=1; i < N; i++)
		fat[i] = m(i, fat[i-1]);
}

ll fast_exp(ll x, ll y){
	ll ans = 1;
	ll tmp = x;
	while(y){
		if(y%2 == 1) ans = m(ans, tmp);
		tmp = m(tmp, tmp);
		y /= 2;
	}
	return ans;
}

ll d(ll x, ll y){
	return m(x, fast_exp(y, MOD-2));
}

ll sm(ll x, ll y){
	return (x + y) % MOD;
}

ll sb(ll x, ll y){
	return (MOD + (x%MOD) - (y%MOD)) % MOD;
}

ll ncr(ll x, ll y){
	return d(fat[x+y], m(fat[x], fat[y]));
}

int main(){
	build();
	ll h, w, a, b;

	cin >> h >> w >> a >> b;
	
	ll rm = 0;
	ll ans = 0;
	for(ll i=1; i <= h-a; i++){
		ll x1 = b;
		ll y1 = i-1;
		ll x2 = h-i;
		ll y2 = w-b-1;
		ll tmp1 = ncr(x1, y1);
		ll tmp2 = ncr(x2, y2);
		ans = sm(ans, m(sb(tmp1, rm), tmp2));
		rm = tmp1;
	}
	cout << ans << endl;
}