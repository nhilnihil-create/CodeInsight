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

vector<ll> ka[101010];

ll rec(ll x){
	if(ka[x].size()==0) return 0;
	vector<ll> list;
	REP(i, ka[x].size()){
		list.push_back(rec(ka[x][i]));
	}
	sort(list.rbegin(), list.rend());
	ll res = -1;
	REP(i, list.size()){
		res = max(res, list[i]+i+1);
	}
	return res;
}

int main(){
	ll N;
	cin >> N;
	REP(i, N-1){
		ll a;
		cin >> a;
		a--;
		ka[a].push_back(i+1);
	}

	cout << rec(0) << endl;
    return 0;
}