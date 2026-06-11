
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)
#define IN(i,a,b) (a<=i&&i<=b)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n;
	ll a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	ll m = abs(b-a);
	bool found = 0;
	f(x,0,n) found |= IN(m,c*(n-1-x)-d*x,d*(n-1-x)-c*x);
	cout << (found?"YES":"NO") << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

