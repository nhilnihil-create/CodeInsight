#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<P> x(n);
	REP(i,n) {
		cin>>x[i].first;
		x[i].first--;
		x[i].second=i+1;
	}
	sort(ALL(x));
	vector<ll> ans(n*n,-1);
	ll pos=0;
	REP(i,n) {
		ans[x[i].first]=x[i].second;
		REP(j,x[i].second-1) {
			if(pos==x[i].first) {
				cout<<"No"<<endl;
				return 0;
			}
			if(ans[pos]!=-1) j--;
			else ans[pos]=x[i].second;
			pos++;
		}
	}
	REP(i,n) x[i].first=n*n-1-x[i].first;
	sort(ALL(x));
	reverse(ALL(ans));
	pos=0;
	REP(i,n) {
		REP(j,n-x[i].second) {
			if(pos==x[i].first) {
				cout<<"No"<<endl;
				return 0;
			}
			if(ans[pos]!=-1) j--;
			else ans[pos]=x[i].second;
			pos++;
		}
	}
	reverse(ALL(ans));
	cout<<"Yes"<<endl;
	DUMP(ans);
}
