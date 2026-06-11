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
	ll M;
	cin >> M;
	ll N = -1;
	vector<ll> kosu(110, 0);
	REP(i, M){
		ll a;
		cin >> a;
		kosu[a]++;
		N = max(N, a);
	}
	bool flag = true;
	if(N%2==0){
		for(int i=N/2+1;i<=N;i++){
			if(kosu[i]<2){
				flag = false;
				break;
			}else{
				kosu[i] -= 2;
			}
		}
		if(kosu[N/2]<1){
			flag = false;
		}
		kosu[N/2] -= 1;
		REP(i, 110){
			if(i<N/2+1||i>N){
				if(kosu[i]>0){
					flag = false;
					break;
				}
			}
		}
	}else{
		for(int i=(N+1)/2;i<=N;i++){
			if(kosu[i]<2){
				flag = false;
				break;
			}else{
				kosu[i] -= 2;
			}
		}
		REP(i, 110){
			if(i<(N+1)/2+1||i>N){
				if(kosu[i]>0){
					flag = false;
					break;
				}
			}
		}
	}
	cout << (flag?"Possible":"Impossible") << endl;
    return 0;
}