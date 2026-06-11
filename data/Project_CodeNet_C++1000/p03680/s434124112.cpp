    #include <iostream>
    using namespace std;
     
    int main() {
    	int n, a[100005], ans = 0, now = 1;
    	cin >> n;
    	for (int i = 1; i <= n; i++) cin >> a[i];
     
    	while (now != 2) {
    	    now = a[now];
    	    ans++;
    	    if (ans > n) break;
    	}
    	if (ans < n) cout << ans;
    	else cout << -1;
    	return 0;
    }