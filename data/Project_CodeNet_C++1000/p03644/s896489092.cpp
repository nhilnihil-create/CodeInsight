#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; i*=2) {
		ans = max(ans, i);
	}
	cout << ans << endl;
    return 0;
}