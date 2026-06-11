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
	int w, h; cin >> w >> h;
	int hony = w + 1, honx = h + 1;
	vector<pair<ll, int> > c;
	REP(i, w){
		cin >> tmp;
		c.push_back(make_pair(tmp, 0));
	}
	REP(i, h){
		cin >> tmp;
		c.push_back(make_pair(tmp, 1));
	}
	sort(c.begin(), c.end());
	REP(i, w+h){
		if(c[i].second == 0){
			ans += c[i].first * honx;
			//cout << c[i].first << " " << honx << endl;
			hony--;
		}
		else{
			ans += c[i].first * hony;
			//cout << c[i].first << " " << hony << endl;
			honx--;
		}
	}
	cout << ans << endl;
}