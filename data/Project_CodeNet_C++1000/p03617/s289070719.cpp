#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

int main(void){

	ll Q, H, S, D; cin >> Q >> H >> S >> D;
	ll N; cin >> N;

	ll x = min(min(4*Q, 2*H), S);

	ll ans = min(D*(N/2)+x*(N%2), x*N);
	cout << ans << endl;


	return 0;

}
