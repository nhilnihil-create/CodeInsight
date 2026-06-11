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

ll sum[100010], sum2[100010];

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	int n, m; cin >> n >> m;
	vi a(n); rep(i, n) cin >> a[i], a[i]--;
	
	rep(i, n - 1){
		int l = a[i], r = a[i + 1];
		if(l < r){
			/*
			rep(j, m){
				if(l < j && j <= r) cnt[j] += r - j + 1;
				else cnt[j] += r - l;
			}
			*/
			sum[0] += r - l;
			sum[l + 1] -= r - l;
			sum[r + 1] += r - l;
			
			sum[l + 1] += r + 1;
			sum[r + 1] -= r + 1;
			sum2[l + 1]--;
			sum2[r + 1]++;
		}
		else{
			/*
			rep(j, m){
				if(j <= r) cnt[j] += r - j + 1;
				else if(j > l) cnt[j] += r + m - j + 1;
				else cnt[j] += r + m - l;
			}
			*/
			sum[0] += r + 1;
			sum[r + 1] -= r + 1;
			sum2[0]--;
			sum2[r + 1]++;
			
			sum[l + 1] += r + m + 1;
			sum2[l + 1]--;
			
			sum[r + 1] += r + m - l;
			sum[l + 1] -= r + m - l;
		}
	}
	//rep(i, m) dbg(i, cnt[i]);
	
	rep(i, m){
		sum[i + 1] += sum[i];
		sum2[i + 1] += sum2[i];
		sum[i] += sum2[i] * i;
		//dbg(i, sum[i]);
	}
	cout << *min_element(sum, sum + m) << endl;
	
	return 0;
}