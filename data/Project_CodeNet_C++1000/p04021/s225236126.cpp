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
	int n; cin >> n;
	vector<int> a(n); cin >> a;
	vector<int> so(n); REP(i, n) so[i] = a[i];
	sort(so.begin(), so.end());
	REP(i, n){
		auto it = lower_bound(so.begin(), so.end(), a[i]);
		//cout << *it << endl;
		int j = distance(so.begin(), it);
		if((j - i) % 2 != 0) ans++;
	}
	cout << ans / 2 << endl;
}
