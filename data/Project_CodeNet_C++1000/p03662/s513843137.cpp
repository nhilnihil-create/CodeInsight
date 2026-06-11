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

int N, deep;
vector<int> edge[100005];
int color[100005]={};
int dfs(int n, int b = -1, int d = 0){
	if( n == N-1 ){
		deep = d;
		return n;
	}
	for(auto t: edge[n]) if(t != b){
		int r = dfs(t, n, d+1);
		if( r > 0 ){
			if( d > deep / 2 ) color[n] = 2;
			else color[n] = 1;
			return r;
		}
	}
	return 0;
}

int dfs2(int n, int b = -1, int c = -1){
	color[n] = c;
	for(auto t: edge[n]) if(t != b && color[t] == 0){
		dfs2(t, n, c);
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> N;
	rep(i,N-1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	color[0] = 1;
	color[N-1] = 2;

	dfs(0);
	rep(i,N) if(color[i] != 0){
		dfs2(i, -1, color[i]);
	}

	int count[5]={};
	rep(i,N) count[ color[i] ]++;

	//cout << count[1] << " " << count[2] << endl;

	if( count[1] > count[2] ){
		cout << "Fennec" << endl;
	}else{
		cout << "Snuke" << endl;
	}

	return 0;
}