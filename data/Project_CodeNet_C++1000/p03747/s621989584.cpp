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

const ll INF = 1e9+7;


int main(){
	ios_base::sync_with_stdio(false);
	ll N, L, T;
	ll X[100005], W[100005];

	cin >> N >> L >> T;
	rep(i,N) cin >> X[i] >> W[i];

	ll loop = T / L;
	ll cnt = 0;
	rep(i,N) if( W[0] != W[i] ) cnt += 2;
	cnt *= loop;

	rep(i,N) if( W[0] != W[i] ){
		ll a = X[0];
		ll b = X[i];
		if( W[0] == 2 ) a += L;
		if( abs(a-b) <= 2 * (T % L) ) cnt++;
		if( abs(a-b) + L <= 2 * (T % L) ) cnt++;
	}

	//cout << "cnt: " << cnt << endl;

	cnt %= N;

	vector<pair<ll,pii>> v;
	rep(i,N){
		if( W[i] == 1 ) v.emplace_back((X[i] + T%L    )%L, pii(-W[i], i));
		if( W[i] == 2 ) v.emplace_back((X[i] + L - T%L)%L, pii(-W[i], i));
	}
	sort(all(v));

	//for(auto t: v) cout << t.X << "," << t.Y.X << "," << t.Y.Y << endl;

	int pos;
	rep(i,N) if( v[i].Y.Y == 0 ){
		//cout << "init pos: " << i << endl;
		if( W[0] == 1 ) pos = (i + N - cnt) % N;
		if( W[0] == 2 ) pos = (i + N + cnt) % N;
		break;
	}

	rep(i,N){
		cout << v[pos].X << endl;
		pos = (pos + 1) % N;
	}

	return 0;
}