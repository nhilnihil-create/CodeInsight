#include <bits/stdc++.h>

using namespace std;

#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORD(i, m, n) for (int i = m; i >= n; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REP1(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a,b,c;
	cin>>a>>b>>c;
	int ab,bc,ca;
	int ans=0;
	while(1){
		if(a==b&&b==c&&a%2==0){
			cout << -1 << endl;
			return 0;
		}
		if(a%2==1||b%2==1||c%2==1){
			break;
		}
		ab=a/2+b/2;
		bc=b/2+c/2;
		ca=c/2+a/2;
		a=bc;
		b=ca;
		c=ab;
		ans++;
	}
	cout << ans << endl;

	return 0;
}