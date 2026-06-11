#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back

struct BIT {
private:
	vector<ll> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n + 1, 0);
	}
	void add(int i, ll x) {
		while(i <= n) {
			node[i] += x;
			i += i & -i;
		}
	}
	ll sum(int i) {
		ll ret = 0;
		while(i > 0) {
			ret += node[i];
			i -= i & -i;
		}
		return ret;
	}
	ll sum(int a, int b) {
        return sum(b) - sum(a - 1);
    }
};

void Yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
 
void No(){
	cout<<"No"<<endl;
	exit(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int N; cin >> N;
  ll K; cin >> K;
  vector<ll> a(N), x(N + 1), y(N + 1);
  x[0] = 0; y[0] = 0;
  rep(i, N) {
	  cin >> a[i];
	  a[i] -= K;
	  x[i + 1] = x[i] + a[i];
	  y[i + 1] = x[i + 1];
  }
  sort(all(y));
  y.erase(unique(all(y)), y.end());
  map<ll, int> mp;
  rep(i, N + 1) mp[y[i]] = i + 1;

  rep(i, N + 1) x[i] = mp[x[i]];

  BIT b(N + 1);
  ll ans = 0;
  rep(i, N + 1) {
	  ans += b.sum(x[i]);
	  b.add(x[i], 1);
  }

  cout << ans << endl;
  return 0;
} 