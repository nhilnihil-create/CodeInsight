//p_i = iなら〇, p_i ≠ iなら×をi=1,2,…について書いた列を考える。この列を×××…にするのが目的となる。
//〇×→××, 〇〇→××, ××→×× or 〇〇, に注意すると、〇の個数 - 「〇〇」をいくつ作れるか、が答えになりそうと分かる。
//(やみくもにバブルソートの交換回数を考えると嵌ります。)
//(操作を分かりやすく描けないか考えてみましょう。)
#include <iostream>
#define rep(i, n) for (i = 0; i < n; i++)
using namespace std;

int n;
int p[100000];
bool flag[100000];

int main() {
	int i;
	int ans = 0;
	
	cin >> n;
	rep(i, n) { cin >> p[i]; p[i]--; }
	rep(i, n) { flag[i] = (p[i] == i); ans += flag[i]; }
	
	rep(i, n - 1) {
		if (flag[i] && flag[i + 1]) {
			flag[i] = false;
			flag[i + 1] = false;
			ans--;
		}
	}
	cout << ans << endl;
	return 0;
}