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
	ll x, y; cin >> x >> y;
	if(x * y > 0){
		if(x <= y) cout << y-x << endl;
		else cout << x-y + 2 << endl;
	}
	else if(x * y < 0) cout << abs(abs(x)-abs(y)) + 1 << endl;
	else{
		if(x <= y) cout << y-x << endl;
		else cout << x-y + 1 << endl;
	}
}