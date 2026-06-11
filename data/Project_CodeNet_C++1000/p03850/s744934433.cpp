#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 100005;
const ll inf = 1LL << 60;
int main()
{
	ios::sync_with_stdio(0);
	int n;
	static int A[Maxn];
	static char op[Maxn];
	static ll dp[Maxn][3];
	cin >> n;
	for(int i=1;i<=n;i++) {
		if(i != 1)
			cin >> op[i];
		else 
			op[i] = '+';
		cin >> A[i];
		if(op[i] == '-')
			A[i] *= -1;
	}
	
	for(int i=1;i<=n;i++)
		for(int j=0;j<=2;j++)
			dp[i][j] = -inf;
	dp[1][0] = A[1];
	for(int i=1;i<n;i++)
		for(int j=0;j<=2;j++)
			if(dp[i][j] != -inf) {
				for(int q1=0;q1<2;q1++)
					for(int q2=0;q2<2;q2++) {
						if(op[i+1] != '-' && q2)
							continue;

						int t = j;
						if(q1 != 0)
							t--;
						if(t < 0)
							continue;
#define sg(a) (((a) % 2 == 0) ? 1 : -1)
						int val = A[i+1] * sg(t);
						if(q2 != 0)
							t++;
						if(t > 2)
							continue;
#define upd(a,b) a = max(a , b)
						upd(dp[i+1][t] , dp[i][j] + val);
#undef upd
#undef sg
					}
			}
	cout << max(dp[n][0] , dp[n][1]) << endl;
	return 0;
}
