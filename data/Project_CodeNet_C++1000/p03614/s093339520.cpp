#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <cstdio>
#define INF 1000000000000
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;
using namespace std;

int main(){
	int n;
	cin >> n;
	int p[n];
	REP(i, n) cin >> p[i];
	int ans = 0;
	REP(i, n-1){
		if(i + 1 == p[i]){
			int t = p[i+1];
			p[i+1] = p[i];
			p[i] = t;
			ans++;
		}
	}
	if(p[n-1] == n) ans++;
	cout << ans << endl;
	return 0;
}
