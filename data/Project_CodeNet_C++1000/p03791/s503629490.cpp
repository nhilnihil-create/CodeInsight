#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

ll N;
const ll MOD = 1e9 + 7;

int main()
{
	scanf("%lld",&N);
	vector<ll> A(N);
	FOR(i,0,N){
		scanf("%lld",&A [i]);
	}
	ll ans = 1,r = 0,cnt = 1;
	FOR(i,0,N){
		while(r < N && A [r] >= cnt){
			r++;
			cnt += 2;
		}
		(ans *= min(N - i,(r - i) + 1)) %= MOD;
		cnt -= 2;
	}

	printf("%lld\n",ans);

	return 0;
}
