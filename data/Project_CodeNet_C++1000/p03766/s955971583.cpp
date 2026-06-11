#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a, b) for(int i=a;i<b;++i)
#define fj(a, b) for(int j=a;j<b;++j)
#define fk(a, b) for(int k=a;k<b;++k)
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
////////////////////////////////

int const N = 1e6 + 41;
int const MOD = 1e9 + 7;

void add(ll &a, ll b){
	a += b;
	a %= MOD;
	if(a < 0) a += MOD;
}

ll sum(ll a, ll b){
	return (a + b) % MOD;
}

ll mul(ll a, ll b){
	return (a * 1LL * b % MOD);
}



ll d[N];
ll F[N];

void upd(int x, int v){
	while(x < N){
		add(F[x], v);
		x |= (x + 1);
	}
}

ll get(int x){
	ll ret = 0;
	while(x >= 0){
		add(ret, F[x]);
		x = (x&(x+1)) -1;
	}
	return ret;
}

void solve(){
	int n;
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return;
	}

	ll ans = 1;
	ll cur = 1;
	for(int i=1;i<=n;++i){
		add(cur, get(i-1));
		if(i < n){
			add(ans, mul(cur, mul(n-1, n)));
		}else{
			add(ans, mul(cur, i-1));
		}
		upd(i+2, cur);
	}
	printf("%lld\n",ans);
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();



	return 0;
}