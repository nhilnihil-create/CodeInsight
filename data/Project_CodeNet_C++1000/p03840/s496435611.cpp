#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
const ll MOD = (ll)1e9+7;
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

bool was_output = false;
template<class t>
void output(t x){
	if(was_output)cout << " ";
	was_output = true;
	cout << x;
}

void outendl(){
	was_output = false;
	cout << endl;
}

int main(){
	ll a, b, c, d, e, f, g;
	cin >> a >> b >> c >> d >> e >> f >> g;
	auto func = [&](vector<int> order){
		ll res = b*2;
		ll na = a;
		ll nd = d;
		ll ne = e;
		foreach(i, order){
			if(i==0){
				if(na>0&&nd>0&&ne>0){
					res += 6;
					--na;
					--nd;
					--ne;
				}
			}
			if(i==1){
				res += na/2*4;
				na&=1;
			}
			if(i==2){
				res += nd/2*4;
				nd&=1;
			}
			if(i==3){
				res += ne/2*4;
				ne&=1;
			}
		}
		return res;
	};
	ll ans = 0;
	vector<int> order(4);
	iota(all(order), 0);

	do{
		chmax(ans, func(order));
	}while(next_permutation(all(order)));

	cout << ans / 2 << endl;


	return 0;
}

