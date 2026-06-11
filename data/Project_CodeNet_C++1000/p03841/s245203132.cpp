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

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	int n; cin >> n;
	vi ans(n * n);
	vector<vector<tuple<int,int,int>>> v(n * n + 1); //(num, lim, count);
	rep(i, n){
		int x; cin >> x;
		ans[x - 1] = i + 1;
		v[0].emplace_back(i + 1, x - 1, i);
		v[x].emplace_back(i + 1, n * n, n - i - 1);
	}
	dbg(ans);
	
	priority_queue<pi> q;
	rep(i, n * n){
		for(auto j : v[i]){
			int a, b, c; tie(a, b, c) = j;
			rep(it, c) q.emplace(-b, a);
		}
		if(ans[i]) continue;
		//dbg(i, ans, q.size());
		
		if(q.empty() || -q.top().first <= i){
			cout << "No" << endl;
			return 0;
		}
		ans[i] = q.top().second;
		q.pop();
	}
	cout << "Yes" << endl;
	rep(i, n * n) cout << ans[i] << (i==n*n-1?"\n":" ");
	
	return 0;
}