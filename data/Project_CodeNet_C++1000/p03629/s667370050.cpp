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


int d[300005] = {};
int main(){
	ios_base::sync_with_stdio(false);
	string S;

	cin >> S;
	S = "a" + S;
	int N = S.length();

	vector<int> to(30,-1);
	vector<int> edge[300005];
	rrep(i,N){
		edge[i] = to;
		to[ S[i] - 'a' ] = i;
	}

	string ans;
	queue<pair<int,string>> que;
	que.emplace();
	while( !que.empty() ){
		int i = que.front().X;
		string s = que.front().Y;
		que.pop();
		rep(k,26) if( ans.empty() ){
			string ns = s + (char)('a' + k);
			if( edge[i][k] < 0 ) ans = ns;
			else{
				int ni = edge[i][k];
				if( d[ni] ) continue;
				d[ni] = s.length();
				que.emplace(ni, ns);
			}
		}
	}

	cout << ans << endl;

	return 0;
}