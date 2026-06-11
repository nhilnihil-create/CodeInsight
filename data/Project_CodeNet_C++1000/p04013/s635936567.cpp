#include<bits/stdc++.h>

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)a, i##_len=(b); i<i##_len; i++)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define int long long

using namespace std;

using P = pair<int, int>;
using ll = long long;

const long long INF = LLONG_MAX/3;
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

class UnionFind{
	std::vector<int> par,siz;
	void init(int n){
		par.resize(n);
		for(int i=0;i<n;i++)par[i]=i;
		siz.resize(n,1);
	}
public:
	UnionFind(int n){
		init(n);
	}
	int root(int n){
		if(par[n]==n)return n;
		else return par[n]=root(par[n]);
	}
	bool issame(int x,int y){
		return (root(x)==root(y));
	}
	bool marge(int a,int b){
		if(issame(a,b))return false;
		else{
			a=root(a),b=root(b);
			if(siz[a]<siz[b])swap(a,b);
			siz[a]+=siz[b];
			par[a]=par[b];
			return true;
		}
	}
	int size(int n){
		return siz[root(n)];
	}
};

long long gcd(long long a,long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long i,long long j){
    return i*(j/gcd(i,j));
}

signed main(){
	int n,a;
	cin>>n>>a;
	int x[100];
	rep(i,n)cin>>x[i];
	rep(i,n)x[i]-=a;
	int cnt=0;
	rep(i,n){
		if(x[i]==0)cnt++;
	}
	int ans=pow(2,cnt)-1;
	int dpp[3000]={},dpm[3000]={};
	dpp[0]=1;dpm[0]=1;
	rep(i,n){
		if(x[i]<0){
			int dpm2[3000]={};
			rep(j,3000){
				if(dpm[j]>0){
					dpm2[j]+=dpm[j];
					dpm2[j-x[i]]+=dpm[j];
				}
			}
			rep(j,3000)dpm[j]=dpm2[j];
		}
		if(x[i]>0){
			int dpp2[3000]={};
			rep(j,3000){
				if(dpp[j]>0){
					dpp2[j]+=dpp[j];
					dpp2[j+x[i]]+=dpp[j];
				}
			}
			rep(j,3000)dpp[j]=dpp2[j];
		}
	}
	int c=0;
	rep(i,1,3000){
		c+=dpp[i]*dpm[i];
	}
	debug(c);
	ans+=c*pow(2,cnt);
	cout<<ans<<endl;
}