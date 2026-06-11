//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = 0;
	int tmp;
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	int mid = INF, ma = 0;
	REP(i, n)ma = max(a[i], ma);
	REP(i, n-1)if(a[i+1] != a[i]) mid = min(mid, a[i+1] - a[i]);
	bool an = false;
	REP(i, n) if(k%mid == a[i]%mid) an = true;
	if(k > ma) an = false;
	if (an) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
	
	//cout << ans << endl;
}