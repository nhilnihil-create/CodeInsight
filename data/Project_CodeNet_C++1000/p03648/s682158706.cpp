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
	ll K;
	cin >> K;

	cout << 50 << endl;
	vector<ll> a(50);
	REP(i, 50) a[i] = 49 + (K/50);
	ll ama = K%50;
	REP(i, 50) a[i] -= ama;
	REP(i, ama) a[i] += 51;
	REP(i, 50) cout << a[i] << " ";
	cout << endl;
    return 0;
}