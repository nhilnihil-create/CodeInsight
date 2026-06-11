#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template < typename T >
void vprint(T &v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

ll dominate(ll A, ll B){
	ll Z = ~A & B;
	return (Z==0);
}

int main(){
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N), B(N);
	REP(i, N) cin >> A[i] >> B[i];

	ll C = K;
	ll res = 0;
	REP(i, N){
		if(dominate(C, A[i])) res += B[i];
	}
	REP(i, 32){
		if(K>>i&1==1){
			C = K;
			C &= ~(1<<i);
			C |= (1<<i)-1;
			ll tmp = 0;
			REP(i, N){
				if(dominate(C, A[i])){
					tmp += B[i];
				}
			}
			res = max(res, tmp);
		}
	}
	cout << res << endl;
    return 0;
}