#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
#define override_rep(i, l, r, mes, ...) mes
#define rep1(i, n) for (int i = 0; i < n; i++)
#define rep2(i, l, r) for (int i = l; i < r; i++)
#define rep(...) override_rep(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define int long long
signed main(signed argc, char* argv[]) {
	int n;
	cin >> n;
	vector<int> t(n + 1), a(n + 1);
	t[0] = 0;
	rep(i, n) cin >> t[i + 1];
	rep(i, n) cin >> a[i];
	a[n] = 0;
	int ans = 1;
	rep(i, n) {
		bool b1, b2;
		b1 = a[i] == a[i + 1];
		b2 = t[i] == t[i + 1];
		if (b1 && b2) {
			ans = ans*min(a[i], t[i+1])%1000000007;
		}
		else if (b1) {
		    if(a[i]<t[i+1])ans=0;
		}
		else if (b2) {
            if(a[i]>t[i+1])ans=0;
		}
		else {
		    if(a[i]!=t[i+1])ans=0;
		}
	}
	cout<<ans<<endl;
}