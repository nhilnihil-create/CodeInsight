//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 
#define MODB  998244353

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	int n, m; cin >> n >> m;
	map<ll, int> co, ba;
	REP(i, n){
		cin >> tmp;
		co[tmp]++;
		ba[tmp%m]++;
	}
	REP1(i, m-1){
		if(i != m-i){
			tmp = min(ba[i], ba[m-i]);
			ans += tmp;
			ba[i] -= tmp;
			ba[m-i] -= tmp;
		}
		else{
			ans += ba[i] / 2;
			ba[i] = ba[i] % 2;		
		}
	}
	ans += ba[0] / 2;
	ba[0] = ba[0] % 2;
	REP1(i, 100000){
		if(co[i] >= 2 && ba[i%m] >= 2){
			tmp = min(co[i], ba[i%m]) / 2;
			ans += tmp;
			ba[i%m] -= tmp * 2;
		}
	}
	cout << ans << endl;
}