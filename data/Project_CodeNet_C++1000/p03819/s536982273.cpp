#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair< int, int > Pi;
typedef pair< long long, long long > P;
typedef pair< long long, P > PP;
typedef pair< P, P > PPP;

const double DINF = 5e14, eps = 1e-10;
const long long MOD = 1e9 + 7, INF = 5e18;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()

struct BIT{
	private:
	int n;
	vector<ll>v;
	public:
	BIT(int N){
		v.resize(N);
		n=N;
	}
	void add(int it,int val){
		while(it<=n)v[it]+=val,it+=it&(-it);
	}
	ll sum(int it){
		ll ret=0;
		while(it>0)ret+=v[it],it-=it&(-it);
		return ret;
	}
};

int n,m,l,r;
vector<int>st[300010];
BIT b(300010);

void input(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		st[r-l+1].eb(l);
	}
	return;
}

void solve(){
	ll ans=n;
	for(int i=1;i<=m;i++){
		int plus=0;
		for(int j=i;j<=m;j+=i)plus+=b.sum(j);
		for(int j=0;j<st[i].size();j++){
			b.add(st[i][j],1);
			b.add(st[i][j]+i,-1);
		}
		cout<<ans+plus<<endl;
		ans-=st[i].size();
	}
	return;
}

int main() {
	input();
	solve();
	return 0;
}
