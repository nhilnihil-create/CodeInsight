#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;
const int MAXN = 100005;

int n, a[100005];

int main(){
	lint ans = 0;
	cin >> n;
	int cnt = 1;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		ans += (x - 1) / cnt;
		if(x == cnt || cnt == 1) cnt++;
	}
	cout << ans << endl;
}
