//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	int tmp;
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	REP(i, n) cin >> a[i];
	REP(i, m) cin >> b[i];
	bool res = false, ch;
	REP(p, n){
		REP(q, n){
			if(p+m > n || q+m > n) continue;
			ch = true;
			REP(r, m){
				//cout << a[p].substr(q, m) << " " <<  b[r] << endl;
				if(a[p+r].substr(q, m) != b[r]) ch = false;
			}
			//cout << endl;
			if(ch) res = true;
		}
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	//cout << ans << endl;
}