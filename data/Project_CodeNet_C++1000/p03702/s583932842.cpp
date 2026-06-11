

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

int N, A, B;
vector<int>h;

//k回で殲滅できるか。
//まず全体にB*kのダメージ。
//残ったモンスターに(A-B)の単体攻撃をk回すると考える。

bool check(ll k) {

	ll cnt = 0;
	for (int i = 0; i < N; i++) {
		ll ret = h[i] - (ll)B*k;

		if (ret > 0) {
			cnt += (ret + (A - B) - 1) / (A - B);
		}

	}

	if (k >= cnt)return true;
	else return false;
}

ll bs() {

	ll ng = -1;
	ll ok = 1e9 + 1;

	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;

		if (check(mid)) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}

	return ok;
}

int main() {
	cin >> N >> A >> B;

	h.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}



	cout << bs() << endl;

	return 0;
}