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
	ll N, ans=1e17;
	int a[200005];

	cin >> N;
	rep(i,N) cin >> a[i];

	ll sum = 0;
	rep(i,N) sum += a[i];

	ll s = 0;
	rep(i,N-1){
		s += a[i];
		sum -= a[i];
		chmin(ans, abs(s - sum));
	}

	cout << ans << endl;

	return 0;
}