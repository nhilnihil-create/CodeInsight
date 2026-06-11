#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

const ll M = MOD;

vector<ll> fac(300001);
vector<ll> ifac(300001); 

ll mpow(ll x, ll n){ 
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCb
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

void init()
{
	fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % M;
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; 
    }
}

int main(int argc, char **argv)
{
	ll N, P; cin >> N >> P;
	vector<ll> A(N);
	for (ll i = 0; i < N; ++i) cin >> A[i];

	ll so{0}, sd{0};
	for (ll i = 0; i < N; ++i)
	{
		if (A[i] & 1)
			++so;
		else
			++sd;
	}

	if (so == 0)
	{
		if (P == 0)
		{
			ll res{1};
			for (ll i = 0; i < N; ++i)
				res *= 2;
			std::cout << res << std::endl;
		}
		else
			std::cout << 0 << std::endl;
	}
	else
	{
		ll res{1};
		for (ll i = 0; i < N-1; ++i)
			res *= 2;
		std::cout << res << std::endl;
	}
}