#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll pow(ll a, ll n, ll m) {
	ll ret = 1LL;
	for (; n > 0LL; n >>= 1LL, a = a * a % m) {
		if (n % 2LL == 1LL) {
			ret = ret * a % m;
		}
	}
	return ret;
}

ll cmb(ll x, ll y){
    if(y>x||y<0) return 0LL;
    ll c = 1;
    for(ll i = 0LL; i < y; i++) {
        c *= (x-i);
        c /= i+1;
    }
    return c;
}

int main() {
    ll N,P;
    cin>>N>>P;
    vector<ll> v(N);
    rep(i,N) {
        cin>>v[i];
        v[i] %= 2LL;
    }
    ll a=0,b=0;
    rep(i,N){
        if(v[i] == 0) a++;
        else b++;
    }
    ll cnt = 0;
    for(ll i = 0; i <= b;i += 2){
        cnt += cmb(b,i)*(1LL<<a);
    }
    if(P==1) cout<<(1LL<<N)-cnt<<endl;
    else cout<<cnt<<endl;
}
