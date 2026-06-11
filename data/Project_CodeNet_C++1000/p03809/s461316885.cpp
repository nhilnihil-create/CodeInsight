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

int n, a[100010];
vector<vi> e;

ll maxpair(vector<ll> v){
	if(v.size() < 2) return 0;
	ll res = 0;
	while(v.size() > 1){
		sort(all(v));
		res += min(v[v.size() - 1], v[v.size() - 2]);
		ll d = abs(v[v.size() - 1] - v[v.size() - 2]);
		v.pop_back(); v.pop_back();
		v.pb(d);
	}
	return res;
}
ll maxpair2(vector<ll> v){
	ll res = 0;
	sort(all(v),greater<ll>());
	while(v[1] > 0){
		res++;
		v[0]--; v[1]--;
		sort(all(v),greater<ll>());
		
		if(res > 1000) break;
	}
	return res;
}

ll rec(int c, int p){
	ll sum = 0;
	vector<ll> v;
	for(int i : e[c]) if(i != p) v.pb(rec(i, c));
	
	if(v.empty()) return a[c];
	
	sum = accumulate(all(v), 0ll);
	ll mxp = max(maxpair(v), maxpair2(v));
	
	//dbg(c, p, sum, mxp);
	
	
	bool ng = sum < a[c] || sum - mxp > a[c];
	if(ng){
		cout << "NO" << endl;
		exit(0);
	}
	return 2 * a[c] - sum;
}
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	rep(i, n) cin >> a[i];
	e.resize(n);
	rep(i, n - 1){
		int j, k; cin >> j >> k; j--; k--;
		e[j].pb(k);
		e[k].pb(j);
	}
	int p = -1;
	rep(i, n) if(e[i].size() > 1) p = i;
	if(p < 0){
		cout << (a[0] != a[1] ? "NO" : "YES") << endl;
		return 0;
	}
	
	cout << (rec(p, p) ? "NO" : "YES") << endl;
	
	return 0;
}