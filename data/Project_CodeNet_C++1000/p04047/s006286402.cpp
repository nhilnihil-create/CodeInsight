#include <bits/stdc++.h>
#include <vector>
 
typedef long long ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI=3.14159265358979323846;
 
using namespace std;
 
int main() {
 
	int n;
	cin >> n;
 
	vector<int> a(2*n);
 
	rep(i, n*2) cin >> a[i];

/*
	rep(i, n*2) {
		for(int j = i; j < n*2- 1; j++) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
*/
	sort(a.begin(), a.end());

	int ans = 0;
/*
	rep(i, n*2)
	cout << endl;
 */
	for(int i = 0; i < n*2; i += 2) {
		ans += a[i];
	}
	 
	cout << ans << endl;
}