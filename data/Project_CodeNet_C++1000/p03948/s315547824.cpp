#include<iostream>
#include<algorithm>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;++i)
#define fdr(i,a,b) for(int i=b-1;i>=a;--i)
/////////////

int const N = 1e5 + 41;
int const INF = 1e9 + 41;

int a[N], suf[N], pref[N];
int n, ans;

void solve(){
	int t;
	cin >> n >> t;
	fr(i, 1, n+1) cin >> a[i];
	pref[0] = INF;
	suf[n+1] = -INF;
	fr(i, 1, n+1) pref[i] = min(pref[i-1], a[i]);
	fdr(i, 1, n+1) suf[i] = max(suf[i+1], a[i]);
	int maxi = 0;
	fr(i, 1, n) maxi = max(maxi, suf[i+1] - pref[i]);
	fr(i, 1, n) if(suf[i+1] - a[i] == maxi) ++ans;
	cout << ans << endl;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	solve();

	return 0;
}