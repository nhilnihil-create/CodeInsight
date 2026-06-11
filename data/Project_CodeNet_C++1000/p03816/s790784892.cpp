#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll,ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;

class UnionFind
{
private:
    vector<ll> p;
    vector<ll> rank;
public:
    UnionFind(ll n){
        p.resize(n,-1);
        rank.resize(n,1);
    }
    ll find(ll x){
        if(p[x]<0)return x;
        return p[x]=find(p[x]);
    }
    void unite(ll x,ll y){
        x=find(x);
        y=find(y);
		if(x==y)return;
        if(rank[x]>rank[y])swap(x,y);
        if(rank[x]==rank[y])rank[y]++;
        p[y]+=p[x];
        p[x]=y;
    }
    ll size(ll x){
        return -p[find(x)];
    }
	bool same(ll a, ll b){
		return find(a) == find(b);
	}
};

signed main(){
	//cout << fixed << setprecision(10);
	int n; cin >> n;
	vl a(n);
	map<int,int> mp;
	rep(i,0,n){
		cin >> a[i];
		mp[a[i]]++;
	}
	ll cnt = 0;
	ll ans = mp.size();
	for(auto c:mp){
		//cout << c.first << " " << c.second << endl;
		cnt += (c.second - 1);
	}
	if(cnt % 2 == 1)ans--;
	cout << ans << endl;
}

