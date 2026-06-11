#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())
#define all(a) (a).begin(), (a).end()

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

ll f(ll a, ll x){
	if(a == -1) return -1;
	return max(a,0LL) / x;
}

int main(void){

	ll a, b, x; cin >> a >> b >> x;
	cout << f(b, x) - f(a-1, x) << endl;

	return 0;

}
