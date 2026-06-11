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
	int N;
	int x[505];

	cin >> N;
	rep(i,N){
		cin >> x[i];
		x[i]--;
	}

	vector<pii> v;
	rep(i,N) v.emplace_back(x[i], i);
	sort(all(v));

	vector<int> ans;
	bool able = true;
	rep(i,N){
		int num = ans.size() + i;
		if( v[i].X - num < v[i].Y ){
			able = false;
			break;
		}else{
			rep(j, v[i].Y) ans.push_back(v[i].Y);
		}
	}
	// cout << able << endl;
	// cout << ans << endl;

	vector<pii> rv;
	rrep(i,N) rv.emplace_back(N*N - v[i].X - 1, v[i].Y);
	vector<int> rans;
	rep(i,N){
		int num = rans.size() + i;
		int right = N - rv[i].Y - 1;
		if( rv[i].X - num < right ){
			able = false;
			break;
		}else{
			rep(j, right) rans.push_back(rv[i].Y);
		}
	}
	// cout << able << endl;
	// cout << rans << endl;

	if( !able ){
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	int pos = 0;
	reverse(all(ans));
	//cout << v << endl;
	rep(i,N*N){
		if( i == v[pos].X ){
			cout << v[pos].Y+1 << " ";
			pos++;
		}else{
			if( ans.size() ){
				cout << ans.back()+1 << " ";
				ans.pop_back();
			}else{
				cout << rans.back()+1 << " ";
				rans.pop_back();
			}
		}
	}
	cout << endl;

	return 0;
}