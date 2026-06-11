

#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<queue>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<cstdio>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)

int main() {

	int N; cin >> N;
	vi a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	ll ans = 0;
	
	int i = 0;
	while (i <= N-1) {
		if (a[i] == i + 1) {
			ans++;
			i += 2;
		}
		else {
			i++;
		}
	}
		
	cout << ans << endl;

	return 0;
}