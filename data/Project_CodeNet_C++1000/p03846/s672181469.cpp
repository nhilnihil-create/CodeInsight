#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 2e+9 + 10;
typedef pair<ll, ll> P;


ll fastpow(ll a, ll pw) {
	ll res = 1;
	while (pw) {
		if (pw & 1) res = res * a % MOD;
		a = a * a % MOD;
		pw >>= 1;
	}
	return res;
}

int main() {
    cin>>N;
    vec num(N, 0);
    rep(i,N) {
        cin>>A;
        ++num[A];
    }
    bool ok = true;
    if(N&1) {
        for(int i = 0; i < N; i += 2) if(num[i] != 2 - (i == 0)) ok = false;
    }
    else {
        for(int i = 1; i < N; i += 2) if(num[i] != 2) ok = false;
    }
    cout<<(ok ? fastpow(2, N / 2) : 0)<<endl;
}