#include<bits/stdc++.h>
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9+7;
//const ll MOD = 998244353;
const int INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
using namespace std;
template<class t>
using vvector = vector<vector<t>>;
template<class t>
using vvvector = vector<vector<vector<t>>>;
template<class t>
using priority_queuer = priority_queue<t, vector<t>, greater<t>>;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

#ifdef DEBUG
#define OUTPUT(x) (output(x), outendl())
#else
#define OUTPUT(x) (void)0
#endif

ll modpow(ll x, ll b){
	ll res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

ll modinv(ll x){
	return modpow(x, MOD-2);
}

bool was_output = false;
template<class t>
void output(t a){
	if(was_output)cout << " ";
	cout << a;
	was_output = true;
}
void outendl(){
	was_output = false;
	cout << endl;
}

namespace mapping{
	template<class t>
		auto collect(int n,t f){
			vector<decltype(f())> res(n);
			for(auto &i:res){
				i = f();
			}
			return res;
		}

	template<class t,class f>
		auto mapcar(t x,f func){
			int n = x.size();
			vector<typename t::value_type> res(n);
			auto itr = res.begin();
			for(auto &i:x){
				*itr = func(i);
				++itr;
			}
			return res;
		}
	template<class t,class f>
		void mapc(t x,f func){
			for(auto &i:x){
				func(i);
			}
		}
	template<class t,class u>
		auto sellect(t x,u f){
			vector<typename t::value_type> res;
			for(auto &i:x){
				if(f(i)){
					res.push_back(i);
				}
			}
			return res;
		}

}

using namespace mapping;

ll in(){
	ll res;
	scanf("%lld",&res);
	return res;
}

int main(){
	ll n = in();
	vector<ll> line = collect(n, in);
	if((int)sellect(line, [&](ll x){return x==line[0];}).size()==n){
		cout << ((line[0]==n-1||line[0]*2<=n)?"Yes":"No") << endl;
		return 0;
	}
	ll value_max = *max_element(all(line));
	ll value_min = *min_element(all(line));
	if(value_max-value_min!=1){
		cout << "No" << endl;
		return 0;
	}
	ll min_cnt = sellect(line, [&](ll x){return x==value_min;}).size();
	ll max_cnt = n - min_cnt;
	if((value_max!=min_cnt)&&(max_cnt/(value_max-min_cnt)>=2)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
