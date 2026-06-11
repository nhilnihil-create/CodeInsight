#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line


const int mod = 1e9+7;
int main()
{
	int N;
	cin >> N;
	vector<int> t(N), a(N);
	rep(i,N) cin >> t[i];
	rep(i,N) cin >> a[i];

	vector<P> left(N);
	vector<P> right(N);
	int m = 0;
	map<int,int> rock;
	rep(i,N){
		int l, r;
		if(t[i] > m){
			l = r = t[i];
			m = t[i];
			rock[i] = m;
		} else {
			l = 1;
			r = m;
		}
		left[i] = P(l,r);
	}
	m = 0;
	for(int i = N-1; i>=0; i--){
		int l, r;
		if(a[i] > m){
			l = r = a[i];
			m = a[i];
			rock[i] = m;
		} else {
			l = 1;
			r = m;
		}
		right[i] = P(l,r);
	}
	ll ans = 1;
	rep(i,N){
		// 山が確定しているときに、矛盾している記録があったらダメ
		if(rock[i]){
			if(left[i].second < rock[i] || right[i].second < rock[i]){
				//debug(rock[i]);
				cout << 0 << endl;
				return 0;
			}
		}
		int l = max(left[i].first,right[i].first);
		int r = min(left[i].second, right[i].second);
		ans *= (r-l + 1);
		ans %= mod;
	}
	cout << ans << endl;
}
