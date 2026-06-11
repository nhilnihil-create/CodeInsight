#include <bits/stdc++.h>

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

template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const ll INF = 1e9+7;


int main(){
	ios_base::sync_with_stdio(false);
	ll N;
	deque<int> ans;

	cin >> N;

	if( N == 1 ){
		cout << 2 << endl;
		cout << "1 1" << endl;
		return 0;
	}

	int idx = 1;
	for(ll k=45; k>0; k--){
		if( N & (1ll<<k) ){
			ans.push_back(idx++);
			if( ans.size() > 1 ){
				int f = ans.front();
				ans.pop_front();
				ans.push_front(idx++);
				ans.push_front(f);
			}
		}else if( ans.size() ){
			ans.push_back(idx++);
		}
	}
	ans.push_front(idx++);
	if( N & 1 ) ans.push_front(idx++);

	// verify
	vector<int> v;
	for(auto t: ans) v.push_back(t);
	v.push_back(idx);
	ll dp[10005]={};
	rep(i,v.size()){
		rep(j,i) if( v[j] < v[i] ) dp[i] += dp[j];
		dp[i] += 1;
	}
	//cout << "dp = " << dp[ans.size()]-1 << endl;

	cout << ans.size()*2 << endl;
	rep(i,ans.size()) cout << i+1 << " ";
	for(auto t: ans) cout << t << " ";
	cout << endl;

	return 0;
}