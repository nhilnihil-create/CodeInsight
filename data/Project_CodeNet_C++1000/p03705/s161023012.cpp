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

int main(void){

	ll N, A, B; cin >> N >> A >> B;

	if(A>B){
		cout << 0 << endl;

	}else{

		ll cnt = (N-2)*(B-A);

		ll ans = cnt+1;

		cout << max(ans,0LL) << endl;

	}





	return 0;

}
