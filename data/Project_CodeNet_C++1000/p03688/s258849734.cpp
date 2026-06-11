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

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	int n; cin >> n;
	vector<int> a(n);
	cin >> a;
	int ma = 0, mi = 9999999;
	REP(i, n){
		ma = max(ma, a[i]);
		mi = min(mi, a[i]);
	}
	bool ch;
	if(ma - mi >= 2) ch = false;
	else if(ma - mi == 1){
		int nma = 0, nmi = 0;
		REP(i, n){
			if(a[i] == ma) nma++;
			else nmi++;
		}
		if(nmi + 1 <= ma && ma <= nma / 2 + nmi) ch = true;
		else ch = false;
	}
	else {
		if(n / 2 >= ma || ma == n-1) ch = true;
		else false;
	}
	if (ch) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	//cout << ans << endl;
}