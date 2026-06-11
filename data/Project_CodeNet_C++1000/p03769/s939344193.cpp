#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll cnt(vector<ll>& c) {
	ll ret=0;
	REP(i,(1<<(ll)c.size())) {
		bitset<64> bi(i);
		if(bi.count()%2) continue;
		vector<ll> tmp;
		REP(j,c.size()) {
			if(bi[j]) tmp.pb(c[j]);
		}
		bool d=true;
		REP(i,tmp.size()/2) if(tmp[i]!=tmp[tmp.size()/2+i]) d=false;
		if(d&&tmp.size()) ret++;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> v;
	ll _n=n;
	while(_n>0) {
		v.pb(_n);
		_n=(_n-1)/2;
	}
	reverse(ALL(v));
	vector<ll> a;
	vector<ll> b;
	ll tmp=0;
	if(v[0]==1) {
		a.pb(1);
		b.pb(1);
		tmp=2;
	} else {
		a.pb(2);
		a.pb(1);
		b.pb(1);
		b.pb(2);
		tmp=3;
	}
	FOR(j,1,v.size()) {
		if(v[j]==v[j-1]*2+1) {
			a.insert(a.begin(),tmp);
			b.insert(b.begin(),tmp);
			tmp++;
		} else {
			a.insert(a.begin(),tmp);
			b.insert(b.begin(),tmp);
			tmp++;
			a.insert(a.begin(),tmp);
			b.push_back(tmp);
			tmp++;
		}
		vector<ll> c;
		REP(i,a.size()) c.pb(a[i]);
		REP(i,b.size()) c.pb(b[i]);
		//cout<<cnt(c)<<endl;
	}
	cout<<a.size()+b.size()<<endl;
	REP(i,a.size()) {
		cout<<a[i]<<" ";
	}
	REP(i,b.size()) {
		cout<<b[i];
		if(i==(ll)b.size()-1) cout<<endl;
		else cout<<" ";
	}
}
