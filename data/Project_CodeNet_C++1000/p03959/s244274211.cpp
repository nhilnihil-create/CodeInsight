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

int main(){
	ll N;
	cin >> N;
	vector<ll> T(N), A(N);
	REP(i, N) cin >> T[i];
	REP(i, N) cin >> A[i];

	vector<ll> val(N);
	vector<bool> fix(N);
	bool flag = true;
	REP(i, N){
		ll left, right;
		if(i==0){
			left = T[i];
			right = A[i] - A[i+1];
		}else if(i==N-1){
			left = T[i] - T[i-1];
			right = A[i];
		}else{
			left = T[i] - T[i-1];
			right = A[i] - A[i+1];
		}
		if(left==0&&right==0){
			val[i] = min(T[i], A[i]);
			fix[i] = false;
		}else if(left>0&&right==0){
			if(T[i]>A[i]) flag = false;
			val[i] = T[i];
			fix[i] = true;
		}else if(left==0&&right>0){
			if(T[i]<A[i]) flag = false;
			val[i] = A[i];
			fix[i] = true;
		}else{
			if(T[i]!=A[i]) flag = false;
			val[i] = T[i];
			fix[i] = true;
		}
	}
	ll res = 1;
	REP(i, N){
		if(!fix[i]){
			res *= val[i];
			res %= mod;
		}
	}
	if(!flag) cout << 0 << endl;
	else cout << res << endl;
	return 0;
}