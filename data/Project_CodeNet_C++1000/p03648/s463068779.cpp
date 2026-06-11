#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-7
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll k;
	cin>>k;
	vector<ll> ans(50);
	if(k%50==0) {
		REP(i,50) ans[i]=49+(k/50);
		cout<<50<<endl;
		DUMP(ans);
	} else {
		REP(i,50) {
			if(i<50-k%50) ans[i]=49+(k/50+1)-(k%50+1);
			else ans[i]=49+(k/50+1)+(50-k%50);
		}
		cout<<50<<endl;
		DUMP(ans);
	}
}
