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

bool in(ll x){
	cout << "? " << x << endl;
	string a; cin >> a;
	return a[0] == 'Y';
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	ll x = 9;
	vi nine, ten;
	rep(i, 10){
		nine.pb(in(x));
		x = x * 10 + 9;
	}
	x = 1;
	rep(i, 11){
		ten.pb(in(x));
		x *= 10;
	}
	auto func = [&](){
		rep(i, 10) if(!nine[i]){
			for(int j = i + 1; ; j++){
				if(nine[j]) return j + 1;
			}
		}
		rep(i, 11) if(!ten[i]) return i;
		return 1;
	};
	int digit = func();
	
	ll lo = 1, hi = 10, mid;
	rep(i, digit - 1){
		lo *= 10;
		hi *= 10;
	}
	lo--; hi--;
	
	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		if(in(mid * 10)) hi = mid;
		else lo = mid;
	}
	cout << "! " << hi << endl;
	return 0;
}