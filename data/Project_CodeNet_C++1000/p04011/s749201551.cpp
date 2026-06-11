#include<bits/stdc++.h>

using namespace std;
#define int            long long
#define f(i,n)        for(int i=0;i<(n);++i)
#define fa(i,a,n)     for(int i=a;i<=(n);++i)
#define fd(i,a,n)     for(int i=a;i>=(n);--i)
#define tc 			  int t;cin>>t;f(testcase,t)
#define pii             pair<int,int>
void c_p_c() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

}

int32_t main() {

	c_p_c();
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	int ans = 0;

	ans += (x * min(n, k));
	n -= k;
	if (n > 0)
		ans += (y * n);
	cout << ans;


	return 0;
}
