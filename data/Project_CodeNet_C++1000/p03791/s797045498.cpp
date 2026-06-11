#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n;
int x[100000];

signed main() {
	int i, j;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> x[i];
	for (i = 0; i < n; i++) x[i] -= 2 * i + 1;
	for (i = 0; i < n; i++) x[i] = max(0LL, -x[i]);
	for (i = 0; i < n; i++) x[i] = (x[i] + 1) / 2;
	for (i = 1; i < n; i++) x[i] = max(x[i - 1], x[i]); //ロボットi+1をゴールさせるには最低何体のロボットをゴールさせる必要があるか？
	
	int ans = 1;
	for (i = 1; i < n; i++) {	//ロボットiをゴールさせる
		ans *= i + 1 - x[i - 1];
		ans %= 1000000007;
	}
	cout << ans << endl;
	return 0;
}