#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	n <<= 1;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; i += 2) ans += a[i];
	cout << ans << endl;
	return 0;
}