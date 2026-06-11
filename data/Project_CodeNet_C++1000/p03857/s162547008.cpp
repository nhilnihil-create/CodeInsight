#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const int inf = (int)1e9;const double INF = 1e12, EPS = 1e-9;

const int MX = 200010;
int p1[MX], p2[MX];
int root(int *p, int x){
	if(p[x] == x) return x;
	return p[x] = root(p, p[x]);
}
void merge(int *p, int a, int b){
	a = root(p, a); b = root(p, b);
	if(a != b) p[b] = a;
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	int n, m1, m2; cin >> n >> m1 >> m2;
	map<pi, vi> v;
	vi ans(n);
	
	rep(i, n) p1[i] = p2[i] = i;
	rep(i, m1){
		int a, b; cin >> a >> b; a--; b--;
		merge(p1, a, b);
	}
	rep(i, m2){
		int a, b; cin >> a >> b; a--; b--;
		merge(p2, a, b);
	}
	
	rep(i, n){
		int r1 = root(p1, i);
		int r2 = root(p2, i);
		v[pi(r1, r2)].pb(i);
	}
	for(const auto &p : v){
		for(int i : p.second) ans[i] = p.second.size();
	}
	rep(i, n) cout << ans[i] << (i==n-1?"\n":" ");
	
	return 0;
}