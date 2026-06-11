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
	vector<ll> ai(N);
	REP(i, N){
		ll x;
		cin >> x;
		if(x==i+1) ai[i] = 1;
		else ai[i] = 0;
	}
	ll res = 0;
	REP(i, N){
		if(i==N-1){
			if(ai[i]==1) res++;
		}else{
			if(ai[i]==1){
				if(ai[i+1]==1){
					ai[i+1] = 0;
				}
				res++;
			}
		}
	}
	cout << res << endl;
    return 0;
}