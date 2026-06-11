#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	string x;
	cin >> x;
	int n = x.size();
	
	int ans = n;
	int rem = 0;
	char flag = 'S';
	int tcnt = 0, scnt = 0;
	rep(i,n) {
		if (x[i] == 'S') {
			while (x[i] == 'S' && i < n) 
			{
				scnt++; 
				i++;
			}
			while (x[i] == 'T' && i < n)
			{
				tcnt++;
				i++;
			}
			if (i != n) i--;
			ans -= 2*min(scnt, tcnt);
			
			if (scnt > tcnt) {
				rem = scnt-tcnt;
				scnt = rem;
				tcnt = 0;
			} else {
				scnt = tcnt = 0;
			}
			//cout << scnt << ' ' << tcnt << ' ' << i << endl;
		}
	}
	cout << ans << endl;
	return 0;
}