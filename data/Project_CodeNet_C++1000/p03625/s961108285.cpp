#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<=(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define Eunique(v) v.erase(unique(all(v)),v.end())
#define Eback(s) s.erase(s.end()-1,s.end())
#define rev(v) reverse(all(v))
#define minvec(v) *min_element(all(v))
#define maxvec(v) *max_element(all(v))
#define sumvec(v) accumulate(all(v),0)
#define mapmax(v) v.rbegin()->first
#define mapmin(v) v.begin()->first
#define pb push_back
#define pf push_front
#define mod 1000000007
#define m_p make_pair
#define DOUBLE fixed << setprecision(15)
#define OK puts("OK")
#define OK1 puts("OK1")
#define OK2 puts("OK2")
#define SIZE(s) (int)s.size()
#define INF ((1LL<<62)-(1LL<<31))
#define zero(x,n) setw(x) << setfill('0') << n

typedef long long ll;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;

typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<ll,ll>> vpll;

const double pi = acos(-1.0);

template<class A, class B>
ostream& operator<<(ostream& ost, const pair<A, B>&p) {
	ost << "{" << p.first << ", " << p.second << "} ";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost, const vector<T>&v) {
	ost << "{";
	for (int i = 0; i<(int)v.size(); i++) {
		if (i)ost << " ";
		ost << v[i];
	}
	ost << "} \n";
	return ost;
}

template<class A, class B>
ostream& operator<<(ostream& ost, const map<A, B>&v) {
	ost << "{";
	for (auto p:v) {
		ost << "{" << p.first << ", " << p.second << "} ";
	}
	ost << "} ";
	return ost;
}

template<class T>
inline bool chmax(T& a, T b){if(a<b){a=b;return true;} return false;}

template<class T>
inline bool chmin(T& a, T b){if(a>b){a=b;return true;} return false;}

ll gcd(ll x, ll y) {return __gcd(x,y);}
ll lcm(ll x, ll y) {return x/__gcd(x,y)*y;}

struct UnionFind {
	vector<long long> par;
	UnionFind(long long size):par(size+1,-1){}
	bool unite(long long x,long long y){	//集合の連結
		x=root(x);
        y=root(y);
		if (x!=y){
			if(par[y]<par[x]) swap(x,y);
			par[x]+=par[y];
            par[y]=x;
		}
		return x!=y;
	}
	bool same(long long x,long long y){	//同集合内かの判定
		return root(x)==root(y);
	}
	int root(long long x){	//根を求める
		return par[x]<0?x:par[x]=root(par[x]);
	}
	int size(long long x){	//集合の大きさ
		return -par[root(x)];
	}
};

int main()
{
	ll n,cnt=0,tmp=0;
	cin >> n;
	vll a(n);
	rep(i,n) cin >> a[i];
	sort(rall(a));
	rep(i,n){
		cnt++;
		if(cnt==4){
			cout << a[i]*a[i] << endl;
			return 0;
		}
		else if(cnt==2){
			if(tmp==0) tmp=a[i];
			else{
				cout << tmp*a[i] << endl;
				return 0;
			}
		}
		if(a[i]!=a[i+1] && i!=n-1) cnt=0;
	}
	cout << 0 << endl;
	return 0;
}